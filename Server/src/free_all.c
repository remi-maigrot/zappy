/*
** EPITECH PROJECT, 2023
** Server
** File description:
** free_all
*/


#include "server.h"

void free_all(server_t *server, client_t *clients, game_info_t *game_info)
{
    if (!server)
        return;
    if (server->teams_names && server->ip) {
        free(server->teams_names);
        free(server->ip);
    }
    if (server || clients || game_info) {
        free(server);
        free(clients);
        free(game_info->map);
        free(game_info->ressources);
        free(game_info);
    }
}
