#include "Core.hpp"

void Zappy::Core::handleMapSizeCommand(Zappy::Core& core, std::vector<std::string> args) {
    if (core.m_sfml == nullptr) {
        std::cerr << "Error: no sfml instance [" << args[0] << "]" << std::endl;
        return;
    }
    std::cout << "Map size: " << args[0] << "x" << args[1] << std::endl;
}

void Zappy::Core::handleTileContentCommand(Zappy::Core& core, std::vector<std::string> args) {
    int x = std::stoi(args[0]);
    int y = std::stoi(args[1]);

    if (core.m_sfml == nullptr) {
        std::cerr << "Error: no sfml instance [" << args[0] << "]" << std::endl;
        return;
    }
    std::vector<Zappy::Tile> tiles = core.m_sfml->getTiles();
    for (auto& tile: tiles) {
        if (tile.getX() == x && tile.getY() == y) {
            tile.setFood(std::stoi(args[2]));
            tile.setLinemate(std::stoi(args[3]));
            tile.setDeraumere(std::stoi(args[4]));
            tile.setSibur(std::stoi(args[5]));
            tile.setMendiane(std::stoi(args[6]));
            tile.setPhiras(std::stoi(args[7]));
            tile.setThystame(std::stoi(args[8]));
            return;
        }
    }
    Zappy::Tile tile = Zappy::Tile(x, y, std::stoi(args[2]), std::stoi(args[3]), std::stoi(args[4]), std::stoi(args[5]), std::stoi(args[6]), std::stoi(args[7]), std::stoi(args[8]));
    core.m_sfml->addTile(tile);
    return;
}

void Zappy::Core::handleTeamNameCommand(Zappy::Core& core, std::vector<std::string> args) {
    core.m_sfml->createTeam(args[0]);
}

void Zappy::Core::handleNewPlayer(Core& core, std::vector<std::string> args) {
    Orientation orientation = getOrientationFromNumber(std::stoi(args[3]));
    Zappy::Player new_player = Player(args[0], std::stoi(args[1]), std::stoi(args[2]), orientation, std::stoi(args[4]), args[5]);
    core.m_sfml->addPlayer(new_player);
}

void Zappy::Core::handlePlayerPositionCommand(Zappy::Core& core, std::vector<std::string> args) {
    std::cout << "PLAYER POSITION x" + args[1] + " y " + args[2] <<std::endl;
    Orientation orientation = getOrientationFromNumber(std::stoi(args[3]));
    core.m_sfml->updatePlayerPosition(args[0], orientation, std::stoi(args[1]), std::stoi(args[2]));
}

void Zappy::Core::handlePlayerLevelCommand(Zappy::Core& core, std::vector<std::string> args) {
    if (core.m_sfml == nullptr) {
        std::cerr << "Error: no sfml instance [" << args[0] << "]" << std::endl;
        return;
    }
    std::cout << "Player now level " << args[1] << std::endl; 
}

void Zappy::Core::handlePlayerInventoryCommand(Zappy::Core& core, std::vector<std::string> args) {
    std::string player_name = args[0];
    args.erase(args.begin());
    core.m_sfml->updatePlayerInventory(player_name, args);
}

void Zappy::Core::handleStopCommand(Zappy::Core& core, std::vector<std::string> args) {
    if (core.m_sfml == nullptr) {
        std::cerr << "Error: no sfml instance [" << args[0] << "]" << std::endl;
        return;
    }
    std::cout << "Stop command" << std::endl;
}

void Zappy::Core::handlePlayerResourcesChange(Core& core, std::vector<std::string> command) {
    core.m_server->request("pin #" + command[0] + "\n");
    std::vector<Zappy::Player> players = core.m_sfml->getPlayers();
    Zappy::Player player = players[0];
    for (auto& p : players) {
        if (p.getId() == command[0]) {
            player = p;
            break;
        }
    }
    core.m_server->request("bct " + std::to_string(player.getX()) + " " + std::to_string(player.getY()) + "\n");
}

void Zappy::Core::handlePlayerDeath(Core& core, std::vector<std::string> command) {
    core.m_sfml->removePlayer(command[0]);
}

void Zappy::Core::handleTimeUnit(Core& core, std::vector<std::string> command) {
    if (core.m_sfml == nullptr) {
        std::cerr << "Error: no sfml instance [" << command[0] << "]" << std::endl;
        return;
    }
    core.m_sfml->updateInterval(std::stoi(command[0]));
}
