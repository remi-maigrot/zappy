/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** spawn_ressources
*/

#include "server.h"

static void spawn_food(ressources_t *ressources, map_t *tile)
{
    int max_food = ressources->current_food;
    int random_food = rand() % (max_food + 1);
    tile->food = random_food;
    ressources->current_food -= tile->food;
}

static void spawn_linemate_draumere_and_sibur(ressources_t *ressources,
map_t *tile)
{
    int max_linemate = ressources->current_linemate;
    int random_linemate = rand() % (max_linemate + 1);
    int max_deraumere = ressources->current_deraumere;
    int random_deraumere = rand() % (max_deraumere + 1);
    int max_sibur = ressources->current_sibur;
    int random_sibur = rand() % (max_sibur + 1);

    tile->linemate = random_linemate;
    ressources->current_linemate -= tile->linemate;
    tile->deraumere = random_deraumere;
    ressources->current_deraumere -= tile->deraumere;
    tile->sibur = random_sibur;
    ressources->current_sibur -= tile->sibur;
}

static void spawn_mendiane_phiras_and_thystame(ressources_t *ressources,
map_t *tile)
{
    int max_mendiane = ressources->current_mendiane;
    int random_mendiane = rand() % (max_mendiane + 1);
    int max_phiras = ressources->current_phiras;
    int random_phiras = rand() % (max_phiras + 1);
    int max_thystame = ressources->current_thystame;
    int random_thystame = rand() % (max_thystame + 1);

    tile->mendiane = random_mendiane;
    ressources->current_mendiane -= tile->mendiane;
    tile->phiras = random_phiras;
    ressources->current_phiras -= tile->phiras;
    tile->thystame = random_thystame;
    ressources->current_thystame -= tile->thystame;
}

static void spawn_ressources_on_tile(ressources_t *ressources, map_t *tile)
{
    spawn_food(ressources, tile);
    spawn_linemate_draumere_and_sibur(ressources, tile);
    spawn_mendiane_phiras_and_thystame(ressources, tile);
}

int spawn_ressources(ressources_t *ressources, map_t **map, int height,
int width)
{
    if (!ressources || !map)
        return 84;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            spawn_ressources_on_tile(ressources, &map[i][j]);
        }
    }
    return 0;
}
