/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
**Orientation.cpp for zappy Orientation proprety
*/

#include "Orientation.hpp"

Zappy::Orientation Zappy::getOrientationFromNumber(int orientation) {
    switch (orientation) {
        case 1:
            return Zappy::Orientation::NORTH;
        case 2:
            return Zappy::Orientation::EAST;
        case 3:
            return Zappy::Orientation::SOUTH;
        case 4:
            return Zappy::Orientation::WEST;
        default:
            return Zappy::Orientation::NORTH;
    }
}