/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Core.hpp
*/

#pragma once

#include "Core.hpp"
#include <memory>
#include <vector>
#include "Socket.hpp"

namespace Zappy {

#ifdef __APPLE__
    #define NOEXCEPT noexcept
#else
    #define NOEXCEPT noexcept(true)
#endif

class ServerProtocolException : public std::exception {
    public:
    /**
     * @brief Construct a new Server Protocol Exception by default.
     * 
     * @param message  Message to display.
     */
    ServerProtocolException(const std::string &message): m_message(message) {};
    const char *what() const NOEXCEPT override { return m_message.c_str(); };

    private:
        std::string m_message;
};

class Core;
class Tile;

class ServerProtocol {
    public:
        ServerProtocol(std::reference_wrapper<Core> core);
        ~ServerProtocol() = default;
        /*
         * Get the status of the socket
         * @return: the status of the socket
        */
        int getStatus();
        /*
         * update the core with server new responses
         * @param response: the new response
        */
        std::string update();
        /*
         * Send a request to the server
         * @param request: the request to send
        */
        void request(std::string request);

    private:
        std::reference_wrapper<Core> m_core;
        std::unique_ptr<Zappy::Socket> m_socket;
};

}