#include "Sfml.hpp"

std::vector<Zappy::Tile> Zappy::Sfml::getTiles() const {
    return m_map_tiles;
}

void Zappy::Sfml::addTile(Zappy::Tile tile)
{
    m_map_tiles.push_back(tile);
}

void Zappy::Sfml::drawTiles() {
    for (unsigned long i = 0; i < m_map_tiles.size(); i++) {
        m_window.draw(m_map_tiles[i].draw(m_origin_x, m_origin_y));
    }
}

Zappy::Tile::Tile(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
    : m_x(x), m_y(y), m_food(food), m_linemate(linemate), m_deraumere(deraumere), m_sibur(sibur),
        m_mendiane(mendiane), m_phiras(phiras), m_thystame(thystame), m_selected(false) {
    m_font.loadFromFile("./GUI/assets/arial.ttf");
};

void Zappy::Tile::setFood(int food) {
    m_food = food;
};
void Zappy::Tile::setLinemate(int linemate) {
    m_linemate = linemate;
};
void Zappy::Tile::setDeraumere(int deraumere) {
    m_deraumere = deraumere;
};
void Zappy::Tile::setSibur(int sibur) {
    m_sibur = sibur;
};
void Zappy::Tile::setMendiane(int mendiane) {
    m_mendiane = mendiane;
};
void Zappy::Tile::setPhiras(int phiras) {
    m_phiras = phiras;
};
void Zappy::Tile::setThystame(int thystame) {
    m_thystame = thystame;
};
void Zappy::Tile::setX(int x) {
    m_x = x;
};
void Zappy::Tile::setY(int y) {
    m_y = y;
};
int Zappy::Tile::getX() const {
    return m_x;
};
int Zappy::Tile::getY() const {
    return m_y;
};

sf::RectangleShape Zappy::Tile::draw(int origin_x, int origin_y) {
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    if (m_selected) rectangle.setFillColor(sf::Color::Red);
    else rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition((m_x + origin_x) * 101, (m_y + origin_y) * 101);
    m_rectangle = rectangle;
    return m_rectangle;
}

void Zappy::Tile::displayInfos(sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(m_font);
    text.setString("Tile (" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")" +
        "\nFood: " + std::to_string(m_food) +
        "\nLinemate: " + std::to_string(m_linemate) +
        "\nDeraumere: " + std::to_string(m_deraumere) +
        "\nSibur: " + std::to_string(m_sibur) +
        "\nMendiane: " + std::to_string(m_mendiane) +
        "\nPhiras: " + std::to_string(m_phiras) +
        "\nThystame: " + std::to_string(m_thystame));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window.getSize().x - 300, 0);
    window.draw(text);
}

sf::RectangleShape Zappy::Tile::getRectangleShape() {
    return m_rectangle;
}

void Zappy::Tile::setSelected(bool select) {
    m_selected = select;
}