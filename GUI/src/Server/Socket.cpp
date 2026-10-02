#include "Socket.hpp"
#include <string>

Zappy::Socket::Socket(int port, std::string host) : m_uncompleted_command("") {
    std::cout << "Connecting to server..." << std::endl;
    m_status = m_tcp_socket.connect(host, port);
    if (m_status != sf::Socket::Done) {
        std::cout << "Error connecting to server." << std::endl;
        std::cout << "Make sure the server is online first." << std::endl;
        exit(84);
        // TODO: insert exception
    } else std::cout << "Connected to server" << std::endl;
    m_tcp_socket.setBlocking(false);
    while (getNextResponse() != "WELCOME");
    request("GRAPHIC\n");
    request("sgt\n");
}

Zappy::Socket::~Socket() {
    m_tcp_socket.disconnect();
    std::cout << "Socket closed" << std::endl;
}

void Zappy::Socket::parseResponse(std::string response) {
    bool command_completed = true;
    if (response.size() == 0) return;
    char last_char = response[response.size() - 1];

    if (last_char != '\n') command_completed = false;
    std::vector<std::string> responses = Zappy::split(response, '\n');
    for (size_t i = 0; i < responses.size(); i++) {
        std::string& current_response = responses[i];
        if (m_uncompleted_command != "") {
            current_response = m_uncompleted_command + current_response;
            m_uncompleted_command = "";
        }
        if (current_response != "") {
            if (i == responses.size() - 1 && !command_completed) m_uncompleted_command = current_response;
            else m_responses.push_back(current_response);
        }
    }
}

void Zappy::Socket::responseHandler() {
    char buffer[1024] = {0};
    size_t received;

    m_tcp_socket.receive(buffer, 1023, received);
    std::string tmp{buffer};
    while (tmp.size() > 0) {
        parseResponse(tmp);
        memset(buffer, 0, 1023);
        m_tcp_socket.receive(buffer, 1023, received);
        tmp = buffer;
    }
}

void Zappy::Socket::request(std::string request) {
    const char *data_ptr = request.c_str();
    std::size_t data_size = request.size();
    std::size_t total_sent = 0;
    sf::Socket::Status send_status;

    while (total_sent < data_size) {
        std::size_t sent = 0;
        send_status = m_tcp_socket.send(data_ptr + total_sent, data_size - total_sent, sent);
        if (send_status == sf::Socket::Error) {
            std::cerr << "Failed to send data to the server" << std::endl;
            return;
        }
        total_sent += sent;
    }
}

std::string Zappy::Socket::getNextResponse() {
    std::string response;

    if (m_responses.empty()) responseHandler();
    if (!m_responses.empty()) {
        response = m_responses.front();
        m_responses.erase(m_responses.begin());
    }
    return response;
}

sf::Socket::Status Zappy::Socket::getStatus() {
    return m_status;
}
