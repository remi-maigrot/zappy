/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** refill_map
*/

#include "server.h"

void check_ressources(server_t *server, game_info_t *game_info)
{
    for (int i = 0; i < server->height; i++) {
        for (int j = 0; j < server->width; j++) {
            game_info->ressources->current_food +=
            game_info->map[i][j].food;
            game_info->ressources->current_linemate +=
            game_info->map[i][j].linemate;
            game_info->ressources->current_deraumere +=
            game_info->map[i][j].deraumere;
            game_info->ressources->current_sibur +=
            game_info->map[i][j].sibur;
            game_info->ressources->current_mendiane +=
            game_info->map[i][j].mendiane;
            game_info->ressources->current_phiras +=
            game_info->map[i][j].phiras;
            game_info->ressources->current_thystame +=
            game_info->map[i][j].thystame;
        }
    }
    spawn_ressources(game_info->ressources, game_info->map, server->height,
    server->width);
}

void refill_map(server_t *server, game_info_t *game_info)
{
    struct timeval start_time;
    struct timeval current_time;
    // ! unused - struct timeval tv = {.tv_sec = 0, .tv_usec = 10000};
    double elapsed_time = 0.0;

    gettimeofday(&start_time, NULL);
    server->command_time_execution = (1 / server->freq) * 20;
    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - start_time.tv_sec) +
    (current_time.tv_usec - start_time.tv_usec) / 1000000.0;
    if (elapsed_time >= server->command_time_execution) {
        check_ressources(server, game_info);
        gettimeofday(&start_time, NULL);
    }
}
