/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_map
*/

#include "server.h"

map_t **init_map(ressources_t *ressources , int height, int width)
{
    map_t **map = my_malloc(sizeof(map_t) * height, NULL);

    if (!map || !ressources)
        return NULL;
    for (int i = 0; i < height; i++) {
        map[i] = my_malloc(sizeof(map_t) * width, NULL);
        for (int j = 0; j < width; j++) {
            map[i][j].x = 0;
            map[i][j].y = 0;
            map[i][j].food = 0;
            map[i][j].linemate = 0;
            map[i][j].deraumere = 0;
            map[i][j].sibur = 0;
            map[i][j].mendiane = 0;
            map[i][j].phiras = 0;
            map[i][j].thystame = 0;
        }
    }
    return map;
}

ressources_t *init_ressources(int height, int width)
{
    ressources_t *ressources = my_malloc(sizeof(ressources_t), NULL);

    if (!ressources)
        return NULL;
    ressources->max_food = width * height * 0.5;
    ressources->max_linemate = width * height * 0.3;
    ressources->max_deraumere = width * height * 0.15;
    ressources->max_sibur = width * height * 0.1;
    ressources->max_mendiane = width * height * 0.1;
    ressources->max_phiras = width * height * 0.08;
    ressources->max_thystame = width * height * 0.05;
    ressources->current_food = ressources->max_food;
    ressources->current_linemate = ressources->max_linemate;
    ressources->current_deraumere = ressources->max_deraumere;
    ressources->current_sibur = ressources->max_sibur;
    ressources->current_mendiane = ressources->max_mendiane;
    ressources->current_phiras = ressources->max_phiras;
    ressources->current_thystame = ressources->max_thystame;
    return ressources;
}
