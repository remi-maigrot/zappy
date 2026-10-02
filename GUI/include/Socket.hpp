/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Core.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Network.hpp>
#include <vector>
#include <cstring>
#include "Utils.hpp"

namespace Zappy {
class Socket {

    public:
        Socket(int port, std::string host);
        ~Socket();
        /*
         * Send a request to the server
         * @param request: the request to send
         * @return: the response from the server
        */
        void request(std::string request);
        /*
         * Get the status of the socket
         * @return: the status of the socket
        */
        sf::Socket::Status getStatus();
        /*
         * Get the next response from the server
         * @return: the next response from the server
        */
        std::string getNextResponse();

    private:
        /*
         * Parse the response from the server
         * @param response: the response to parse
        */
        void parseResponse(std::string response);
        /*
         * Listen for a socket from the server
         * @return: a message from the server
        */
        void responseHandler();

        sf::Socket::Status m_status;
        sf::TcpSocket m_tcp_socket;
        std::vector<std::string> m_responses;
        std::string m_uncompleted_command;

};
}