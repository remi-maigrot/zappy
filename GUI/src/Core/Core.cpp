/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "Tile.hpp"

Zappy::Core::Core()
{
    m_connected_to_server = false;
    m_running = false;
}

int Zappy::Core::init(int ac, char **av)
{
    m_port = fetchPort(ac, av);
    m_host = fetchHost(ac, av);

    m_server = std::make_unique<Zappy::ServerProtocol>(std::ref(*this));
    if (m_server->getStatus() < 0) {
        std::cerr << "ServerProtocol failed" << std::endl;
        return -1;
    }
    m_sfml = std::make_unique<Zappy::Sfml>(std::ref(*this));
    m_running = true;
    return 0;
}

int Zappy::Core::fetchPort(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (std::string(av[i]) == "-p") {
            if (i + 1 < ac)
                return atoi(av[i + 1]);
            else
                return -1; // todo: throw exception
        }
    }
    return -1; // todo: throw exception
}

std::string Zappy::Core::fetchHost(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (std::string(av[i]) == "-h") {
            if (i + 1 < ac)
                return std::string(av[i + 1]);
            else
                return "127.0.0.1";
        }
    }
    return "127.0.0.1";
}

void Zappy::Core::run()
{
    std::cout << "Core is running" << std::endl;
    std::cout << "\tPort: " << m_port << std::endl;
    std::cout << "\tHost: " << m_host << std::endl;

    while (m_running) {
        std::string action = m_server->update();
        if (action != "") interpretCommand(action);
        m_sfml->update();
    }
}

void Zappy::Core::stop()
{
    m_running = false;
}

std::map<std::string, std::function<void(Zappy::Core&, std::vector<std::string>)> > Zappy::Core::getCommands() {
    return {
        { "seg", handleStopCommand},
        { "msz", handleMapSizeCommand},
        { "tna", handleTeamNameCommand},
        { "bct", handleTileContentCommand},
        { "pnw", handleNewPlayer },
        { "ppo", handlePlayerPositionCommand},
        { "plv", handlePlayerLevelCommand},
        { "pin", handlePlayerInventoryCommand},
        { "pgt", handlePlayerResourcesChange},
        { "pdr", handlePlayerResourcesChange},
        { "pdi", handlePlayerDeath },
        { "sgt", handleTimeUnit },
        { "sst", handleTimeUnit }
    };
}

void Zappy::Core::interpretCommand(std::string command) {

    std::vector<std::string> parsed_command = Zappy::split(command, ' ');
    std::string order = parsed_command.front();
    std::map<std::string, std::function<void(Zappy::Core&, std::vector<std::string>)> > commands = getCommands();
    auto it = commands.find(order);

    parsed_command.erase(parsed_command.begin());
    if (it != commands.end()) {
        it->second(*this, parsed_command);
    } else {
        std::cout << "Unknown command: [" << command << "]" << std::endl;
    }
}
