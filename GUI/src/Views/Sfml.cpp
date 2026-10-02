/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"
#include <algorithm>

Zappy::Sfml::Sfml(std::reference_wrapper<Core> core) : m_core(core)
{
    std::cout << "Creating Sfml" << std::endl;
    m_window.create(sf::VideoMode(1920, 1080), "Zappy");
    m_window.setFramerateLimit(24);
    m_window.setVerticalSyncEnabled(false);
    m_window.setMouseCursorVisible(true);
    std::cout << "Sfml created" << std::endl;
}

Zappy::Sfml::~Sfml()
{
    m_window.close();
    std::cout << "Sfml destroyed" << std::endl;
}

void Zappy::Sfml::update()
{
    while (m_window.pollEvent(m_event))
        if (m_event.type == sf::Event::Closed)
            m_core.get().stop();
    if (m_clock.getElapsedTime() >= m_clock_interval) {
        handlePlayerKeys();
        m_window.clear(sf::Color::Black);
        drawTiles();
        drawPlayers();
        checkSelected();
        m_window.display();
        m_clock.restart();
    }
}

void Zappy::Sfml::checkSelected()
{
    for (unsigned long i = 0; i < m_players.size(); i++)
        if (m_players[i].isSelected()) m_players[i].displayInfos(m_window);
    for (unsigned long i = 0; i < m_map_tiles.size(); i++)
        if (m_map_tiles[i].isSelected()) m_map_tiles[i].displayInfos(m_window);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(m_window);
        for (unsigned long i = 0; i < m_map_tiles.size(); i++) {
            m_map_tiles[i].setSelected(false);
            if (m_map_tiles[i].getRectangleShape().getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
                m_map_tiles[i].setSelected(true);
                m_map_tiles[i].displayInfos(m_window);
            }
        }
        for (unsigned long i = 0; i < m_players.size(); i++) {
            m_players[i].setSelected(false);
            if (m_players[i].getRectangleShape().getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
                m_players[i].setSelected(true);
                m_players[i].displayInfos(m_window);
            }
        }
    }
}

void Zappy::Sfml::createTeam(std::string team_name)
{
    for (auto &team : m_teams)
        if (team.find(team_name) != team.end()) {
            std::cerr << "Team already exists" << std::endl;
            return;
        }
    std::map<std::string, sf::Color> team;
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    team[team_name] = sf::Color(r, g, b);
    m_teams.push_back(team);
}

void Zappy::Sfml::updatePlayerInventory(std::string player_name, std::vector<std::string> inventory)
{
    for (unsigned long i = 0; i < m_players.size(); i++) {
        if (m_players[i].getId() == player_name) {
            m_players[i].setX(std::stoi(inventory[0]));
            m_players[i].setY(std::stoi(inventory[1]));
            m_players[i].setFood(std::stoi(inventory[2]));
            m_players[i].setLinemate(std::stoi(inventory[3]));
            m_players[i].setDeraumere(std::stoi(inventory[4]));
            m_players[i].setSibur(std::stoi(inventory[5]));
            m_players[i].setMendiane(std::stoi(inventory[6]));
            m_players[i].setPhiras(std::stoi(inventory[7]));
            m_players[i].setThystame(std::stoi(inventory[8]));
            return;
        }
    }
}

void Zappy::Sfml::updatePlayerPosition(std::string player_name, Zappy::Orientation orientation, int x, int y)
{
    for (unsigned long i = 0; i < m_players.size(); i++) {
        if (m_players[i].getId() == player_name) {
            m_players[i].setX(x);
            m_players[i].setY(y);
            m_players[i].setOrientation(orientation);
            return;
        }
    }
}

void Zappy::Sfml::updatePlayerLevel(std::string player_name, int level)
{
    for (unsigned long i = 0; i < m_players.size(); i++) {
        if (m_players[i].getId() == player_name) {
            m_players[i].setLevel(level);
            return;
        }
    }
}

void Zappy::Sfml::removePlayer(std::string player_name) {
    for (unsigned long i = 0; i < m_players.size(); i++) {
        if (m_players[i].getId() == player_name) {
            m_players.erase(m_players.begin() + i);
            return;
        }
    }
}

void Zappy::Sfml::handlePlayerKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_origin_y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_origin_y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_origin_x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_origin_x += 1;
    }
}

void Zappy::Sfml::updateInterval(int interval)
{
    m_clock_interval = sf::milliseconds(interval);
}