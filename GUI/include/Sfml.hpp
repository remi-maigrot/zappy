/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Sfml.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Core.hpp"
#include "Tile.hpp"
#include "Player.hpp"

namespace Zappy {

class Core;

class Sfml {
    public:
        /*
         * Constructor of the sfml
         * @param core: the core of the program
        */
        Sfml(std::reference_wrapper<Zappy::Core> core);
        /*
         * Destructor of the sfml
        */
        ~Sfml();
        /*
         * Update the sfml window
        */
        void update();
        /*
         * Add a tile to the map
         * @param tile: the tile to add
        */
        void addTile(Zappy::Tile tile);
        /*
         * Add a player to the map
         * @param player: the player to add
        */
        void addPlayer(Zappy::Player player);
        /*
         * Get the Tiles of the map
         * @return std::vector<Zappy::Tile>
        */
        std::vector<Zappy::Tile> getTiles() const;
        /*
         * Get the Players of the map
         * @return std::vector<Zappy::Player>
        */
        std::vector<Zappy::Player> getPlayers() const;
        /*
         * Create a new team in the game
         * @param team_name: the name of the team to create
        */
        void createTeam(std::string team_name);
        /*
         * Update the graphical inventory of a player
         * @param player_name: the name of the player
         * @param inventory: the inventory of the player
        */
        void updatePlayerInventory(std::string player_name, std::vector<std::string> inventory);
        /*
         * Update the graphical position of a player
         * @param player_name: the name of the player
         * @param orientation: the orientation of the player
         * @param x: the x position of the player
         * @param y: the y position of the player
        */
        void updatePlayerPosition(std::string player_name, Zappy::Orientation orientation, int x, int y);
        /*
         * Remove a player from the map
         * @param player_name: the name of the player to remove
        */
        void removePlayer(std::string player_name);
        /*
         * Update the graphical level of a player
         * @param player_name: the name of the player
         * @param level: the level of the player
        */
        void updatePlayerLevel(std::string player_name, int level);
        /*
         * Update the clock interval of the sfml
         * @param interval: the new interval of the clock
        */
        void updateInterval(int interval);

    private:
        /*
         * Draw all tiles of the window
        */
        void drawTiles();
        /*
         * Draw all players of the window
        */
        void drawPlayers();
        /*
         * Check if some elements on the map are selected
        */
        void checkSelected();
        /*
         * Handle player keys
        */
        void handlePlayerKeys();

        sf::RenderWindow m_window;
        sf::Event m_event;
        sf::Clock m_clock;
        sf::Time m_clock_interval;
        std::reference_wrapper<Zappy::Core> m_core;
        sf::Font m_font;
        sf::Text m_connection_status;
        std::vector<Zappy::Tile> m_map_tiles;
        std::vector<Zappy::Player> m_players;
        std::vector<std::map<std::string, sf::Color> > m_teams;
        int m_origin_x;
        int m_origin_y;
};

}