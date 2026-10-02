/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Orientation.hpp is the orientation enum
*/

#pragma once

#include <iostream>

namespace Zappy {

enum class Orientation
{
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

/*
 * Get the orientation from an id
 * @param orientation: the id of the orientation
 * @return: the orientation
*/
Orientation getOrientationFromNumber(int orientation);

}