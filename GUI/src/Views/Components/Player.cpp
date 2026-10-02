#include "Sfml.hpp"

std::vector<Zappy::Player> Zappy::Sfml::getPlayers() const {
    return m_players;
}

void Zappy::Sfml::addPlayer(Zappy::Player player)
{
    m_players.push_back(player);
}

void Zappy::Sfml::drawPlayers() {
    for (unsigned long i = 0; i < m_players.size(); i++) {
        std::string player_team = m_players[i].getTeam();
        sf::Color player_color = sf::Color::Black;
        for (auto &team : m_teams)
            if (team.find(player_team) != team.end())
                player_color = team[player_team];
        m_window.draw(m_players[i].draw(player_color, m_origin_x, m_origin_y));
    }
}

Zappy::Player::Player(std::string id, int x, int y, Orientation orientation, int level, std::string team)
    : m_x(x), m_y(y), m_food(0), m_linemate(0), m_deraumere(0), m_sibur(0),
        m_mendiane(0), m_phiras(0), m_thystame(0), m_level(level), m_selected(false), m_orientation(orientation), m_team(team), m_id(id) {
    m_font.loadFromFile("./GUI/assets/arial.ttf");
};

void Zappy::Player::setFood(int food) {
    m_food = food;
};
void Zappy::Player::setLinemate(int linemate) {
    m_linemate = linemate;
};
void Zappy::Player::setDeraumere(int deraumere) {
    m_deraumere = deraumere;
};
void Zappy::Player::setSibur(int sibur) {
    m_sibur = sibur;
};
void Zappy::Player::setMendiane(int mendiane) {
    m_mendiane = mendiane;
};
void Zappy::Player::setPhiras(int phiras) {
    m_phiras = phiras;
};
void Zappy::Player::setThystame(int thystame) {
    m_thystame = thystame;
};
void Zappy::Player::setX(int x) {
    m_x = x;
};
void Zappy::Player::setY(int y) {
    m_y = y;
};
int Zappy::Player::getX() const {
    return m_x;
};
int Zappy::Player::getY() const {
    return m_y;
};

sf::RectangleShape Zappy::Player::draw(sf::Color team_color, int origin_x, int origin_y) {
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    rectangle.setFillColor(team_color);
    rectangle.setPosition((m_x + origin_x) * 101, (m_y + origin_y) * 101);
    m_rectangle = rectangle;
    return m_rectangle;
}

void Zappy::Player::displayInfos(sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(m_font);
    std::string player_facing = "??";
    switch (m_orientation) {
        case Orientation::NORTH:
            player_facing = "North";
            break;
        case Orientation::EAST:
            player_facing = "East";
            break;
        case Orientation::SOUTH:
            player_facing = "South";
            break;
        case Orientation::WEST:
            player_facing = "West";
            break;
    }
    text.setString("Player #" + m_id + " (" + std::to_string(m_x) + ", " + std::to_string(m_y) + ") - lvl " + std::to_string(m_level) +
        "\nFacing: " + player_facing +
        "\nTeam: " + m_team +
        "\nFood: " + std::to_string(m_food) +
        "\nLinemate: " + std::to_string(m_linemate) +
        "\nDeraumere: " + std::to_string(m_deraumere) +
        "\nSibur: " + std::to_string(m_sibur) +
        "\nMendiane: " + std::to_string(m_mendiane) +
        "\nPhiras: " + std::to_string(m_phiras) +
        "\nThystame: " + std::to_string(m_thystame));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window.getSize().x - 300, 300);
    window.draw(text);
}

sf::RectangleShape Zappy::Player::getRectangleShape() {
    return m_rectangle;
}

void Zappy::Player::setSelected(bool select) {
    m_selected = select;
}

void Zappy::Player::setOrientation(Orientation orientation) {
    m_orientation = orientation;
}

void Zappy::Player::setTeam(std::string team) {
    m_team = team;
}

void Zappy::Player::setId(std::string id) {
    m_id = id;
}

Zappy::Orientation Zappy::Player::getOrientation() const {
    return m_orientation;
}

std::string Zappy::Player::getTeam() const {
    return m_team;
}

std::string Zappy::Player::getId() const {
    return m_id;
}

void Zappy::Player::updateRectOrientation() {
    switch (m_orientation) {
        case Orientation::NORTH:
            m_rectangle.setRotation(0);
            break;
        case Orientation::EAST:
            m_rectangle.setRotation(90);
            break;
        case Orientation::SOUTH:
            m_rectangle.setRotation(180);
            break;
        case Orientation::WEST:
            m_rectangle.setRotation(270);
            break;
    }
}

void Zappy::Player::setLevel(int level) {
    m_level = level;
}
