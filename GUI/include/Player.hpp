/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Player.hpp is the player struct
*/

#pragma once
#include "Orientation.hpp"
#include "Tile.hpp"
#include <iostream>

namespace Zappy {

enum class Orientation;

class Player {
    public:
        /*
         * Constructor of the player
         * @param id: the id of the player
         * @param x: the x position of the player
         * @param y: the y position of the player
         * @param orientation: the orientation of the player
         * @param level: the level of the player
         * @param team: the team of the player
        */
        Player(std::string id, int x, int y, Orientation orientation, int level, std::string team);
        /*
         * Destructor of the player
        */
        ~Player() = default;
        /*
         * Set the food of the player
         * @param food: the new food of the player
        */
        void setFood(int food);
        /*
         * Set the linemate of the player
         * @param linemate: the new linemate of the player
        */
        void setLinemate(int linemate);
        /*
         * Set the deraumere of the player
         * @param deraumere: the new deraumere of the player
        */
        void setDeraumere(int deraumere);
        /*
         * Set the sibur of the player
         * @param sibur: the new sibur of the player
        */
        void setSibur(int sibur);
        /*
         * Set the mendiane of the player
         * @param mendiane: the new mendiane of the player
        */
        void setMendiane(int mendiane);
        /*
         * Set the phiras of the player
         * @param phiras: the new phiras of the player
        */
        void setPhiras(int phiras);
        /*
         * Set the thystame of the player
         * @param thystame: the new thystame of the player
        */
        void setThystame(int thystame);
        /*
         * Set the orientation of the player
         * @param orientation: the new orientation of the player
        */
        void setOrientation(Orientation orientation);
        /*
         * Set the team of the player
         * @param team: the new team of the player
        */
        void setTeam(std::string team);
        /*
         * Set the id of the player
         * @param id: the new id of the player
        */
        void setId(std::string id);
        /*
         * Set the x position of the player
         * @param x: the new x position of the player
        */
        void setX(int x);
        /*
         * Set the y position of the player
         * @param y: the new y position of the player
        */
        void setY(int y);
        /*
         * Get the x axis of the player
         * @return the x axis of the player
        */
        int getX() const;
        /*
         * Get the y axis of the player
         * @return the y axis of the player
        */
        int getY() const;
        /*
         * Get the Orientation of the player
         * @return the Orientation of the player
        */
        Orientation getOrientation() const;
        /*
         * Get the team of the player
         * @return the team of the player
        */
        std::string getTeam() const;
        /*
         * Get the id of the player
         * @return the id of the player
        */
        std::string getId() const;

        /*
         * Generate the drawable player
         * @param team_color: the color of the team
         * @param origin_x: the origin x of the map
         * @param origin_y: the origin y of the map
         * @return the rectangle shape of the player
        */
        sf::RectangleShape draw(sf::Color team_color, int origin_x, int origin_y);
        /*
         * Display the infos of the player
         * @param window: the window where the infos will be displayed
        */
        void displayInfos(sf::RenderWindow& window);
        /*
         * Get the rectangle shape of the player
         * @return the rectangle shape of the player
        */
        sf::RectangleShape getRectangleShape();
        /*
         * Set the player as Selected or no
         * @param select: the new selected state of the player
        */
        void setSelected(bool select);
        /*
         * Get the selected state of the player
         * @return the selected state of the player
        */
        bool isSelected() const { return m_selected; };
        /*
         * Update the rectangle shape of the player
        */
        void updateRectOrientation();
        /*
         * Set the level of the player
         * @param level: the new level of the player
        */
        void setLevel(int level);

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
        int m_level;
        sf::RectangleShape m_rectangle;
        sf::Font m_font;
        bool m_selected;
        Orientation m_orientation;
        std::string m_team;
        std::string m_id;
};

}