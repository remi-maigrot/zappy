/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** manage_food
*/

#include "server.h"

static int clear_food(client_t *clients)
{
    if (!clients)
        return 84;
    clients->inventory->food -= 1;
    return 0;
}

int remove_food(server_t *server, client_t *clients, game_info_t *game_info)
{
    if (!server || !game_info)
        return 84;
    struct timeval start_time;
    struct timeval current_time;
    // ! unused var - struct timeval tv = {.tv_sec = 0, .tv_usec = 10000};
    double elapsed_time = 0.0;

    gettimeofday(&start_time, NULL);
    server->command_time_execution = (1 / server->freq) * 126;
    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - start_time.tv_sec) +
    (current_time.tv_usec - start_time.tv_usec) / 1000000.0;
    if (elapsed_time >= server->command_time_execution) {
        clear_food(clients);
        gettimeofday(&start_time, NULL);
    }
    return 0;
}
