/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Core.hpp
*/

#pragma once

#include "ServerProtocol.hpp"
#include "Orientation.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include "Sfml.hpp"
#include "Utils.hpp"

namespace Zappy {

class Tile;
class ServerProtocol;
class Sfml;

class Core {
    public:
        Core();
        ~Core() = default;
        /*
         * Init the core
         * @param ac: number of arguments
         * @param av: arguments
        */
        int init(int ac, char **av);
        /*
         * Run the core
        */
        void run();
        /*
         * get the current server port
         * @return int
        */
        int port() { return m_port; }
        /*
        * get the current server host
        * @return std::string
        */
        std::string host() { return m_host; }
        /*
        * set the current server connection status
        * @param connected: the new connection status
        */
        void setConnectedToServer(bool connected) { m_connected_to_server = connected; }
        /*
         * stop the core
        */
        void stop();

    private:
        /*
         * Fetch the port from the arguments
         * @param ac: number of arguments
         * @param av: arguments
         * @return: the port number of the server
        */
        int fetchPort(int ac, char **av);
        /*
         * Fetch the host from the arguments
         * @param ac: number of arguments
         * @param av: arguments
         * @return: the host of the server
        */
        std::string fetchHost(int ac, char **av);
        /*
         * Interpret server commands
         * @param command: the command to interpret
        */
        void interpretCommand(std::string command);
        /*
         * Get all existing commands
         * @return: a map of all existing commands <name, callback>
        */
        std::map<std::string, std::function<void(Core&, std::vector<std::string>)> > getCommands();

        /*
         * Interpret map size received from server
         * @param command: the command details
        */
        static void handleMapSizeCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret Tile creation command from server
         * @param command: the command details
        */
        static void handleTileContentCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret team received from server
         * @param command: the command details
        */
        static void handleTeamNameCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret new player received from server
         * @param command: the command details
        */
        static void handleNewPlayer(Core& core, std::vector<std::string> command);
        /*
         * Interpret player position received from server
         * @param command: the command details
        */
        static void handlePlayerPositionCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret player level received from server
         * @param command: the command details
        */
        static void handlePlayerLevelCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret player inventory received from server
         * @param command: the command details
        */
        static void handlePlayerInventoryCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret stop command received from server
         * @param command: the command details
        */
        static void handleStopCommand(Core& core, std::vector<std::string> command);
        /*
         * Interpret player resources received from server
         * @param command: the command details
        */
        static void handlePlayerResourcesChange(Core& core, std::vector<std::string> command);
        /*
         * Interpret if a player is dead
         * @param command: the command details
        */
        static void handlePlayerDeath(Core& core, std::vector<std::string> command);
        /*
         * Interpret the time unit of the server
         * @param command: the command details
        */
        static void handleTimeUnit(Core& core, std::vector<std::string> command);

        int m_port;
        std::string m_host;
        std::unique_ptr<ServerProtocol> m_server;
        bool m_connected_to_server;
        std::unique_ptr<Zappy::Sfml> m_sfml;
        bool m_running;
};

}
