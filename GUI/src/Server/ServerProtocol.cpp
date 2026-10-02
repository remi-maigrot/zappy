/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ServerProtocol.cpp is the connection between server and GUI
*/

#include "../include/ServerProtocol.hpp"

Zappy::ServerProtocol::ServerProtocol(std::reference_wrapper<Core> core) : m_core(core) {
    m_socket = std::make_unique<Zappy::Socket>(m_core.get().port(), m_core.get().host());
    if (m_socket->getStatus() != 0) {
        std::cerr << "Socket connection failed" << std::endl;
        ServerProtocolException("Socket failed");
    }
    core.get().setConnectedToServer(true);
}

void Zappy::ServerProtocol::request(std::string request) {
    return m_socket->request(request);
}

std::string Zappy::ServerProtocol::update() {
    std::string response = m_socket->getNextResponse();
    if (response == "ko") {
        std::cerr << "Error: Server KO" << std::endl;
        return "";
        // TODO: insert exception
    }
    return response;
}

int Zappy::ServerProtocol::getStatus() {
    return m_socket->getStatus();
}
