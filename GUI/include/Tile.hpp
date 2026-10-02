/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Tile.hpp is the class for a map tile
*/

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Zappy {

class Tile {
    public:
        /*
         * Constructor of the tile
         * @param x: the x position of the tile
         * @param y: the y position of the tile
         * @param food: the food of the tile
         * @param linemate: the linemate of the tile
         * @param deraumere: the deraumere of the tile
         * @param sibur: the sibur of the tile
         * @param mendiane: the mendiane of the tile
         * @param phiras: the phiras of the tile
         * @param thystame: the thystame of the tile
        */
        Tile(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
        /*
         * Destructor of the tile
        */
        ~Tile() = default;
        /*
         * Set the food of the tile
         * @param food: the new food of the tile
        */
        void setFood(int food);
        /*
         * Set the linemate of the tile
         * @param linemate: the new linemate of the tile
        */
        void setLinemate(int linemate);
        /*
         * Set the deraumere of the tile
         * @param deraumere: the new deraumere of the tile
        */
        void setDeraumere(int deraumere);
        /*
         * Set the sibur of the tile
         * @param sibur: the new sibur of the tile
        */
        void setSibur(int sibur);
        /*
         * Set the mendiane of the tile
         * @param mendiane: the new mendiane of the tile
        */
        void setMendiane(int mendiane);
        /*
         * Set the phiras of the tile
         * @param phiras: the new phiras of the tile
        */
        void setPhiras(int phiras);
        /*
         * Set the thystame of the tile
         * @param thystame: the new thystame of the tile
        */
        void setThystame(int thystame);
        /*
         * Set the x position of the tile
         * @param x: the new x position of the tile
        */
        void setX(int x);
        /*
         * Set the y position of the tile
         * @param y: the new y position of the tile
        */
        void setY(int y);
        /*
         * Get the X position of the tile
         * @return the X position of the tile
        */
        int getX() const;
        /*
         * Get the Y position of the tile
         * @return the Y position of the tile
        */
        int getY() const;

        /*
         * Generate the rectangle shape of the tile
         * @return the rectangle shape of the tile
        */
        sf::RectangleShape draw(int origin_x, int origin_y);
        /*
         * Display the infos of the tile
         * @param window: the window where the tile will be displayed
        */
        void displayInfos(sf::RenderWindow& window);
        /*
         * Get the rectangle shape of the tile
         * @return the rectangle shape of the tile
        */
        sf::RectangleShape getRectangleShape();
        /*
         * Set the selected state of the tile
         * @param select: the new selected state of the tile
        */
        void setSelected(bool select);
        /*
         * Get the selected state of the tile
         * @return the selected state of the tile
        */
        bool isSelected() const { return m_selected; };

    private:
        int m_x;
        int m_y;
        int m_food;
        int m_linemate;
        int m_deraumere;
        int m_sibur;
        int m_mendiane;
        int m_phiras;
        int m_thystame;
        sf::RectangleShape m_rectangle;
        sf::Font m_font;
        bool m_selected;
};
}
