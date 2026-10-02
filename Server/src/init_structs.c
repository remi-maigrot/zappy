/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_structures
*/

#include "server.h"

game_info_t *init_game_info()
{
    game_info_t *client_game_info = my_malloc(sizeof(game_info_t), NULL);

    if (!client_game_info)
        return NULL;
    client_game_info->map = NULL;
    client_game_info->ressources = NULL;
    return client_game_info;
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = my_malloc(sizeof(inventory_t), NULL);

    if (!inventory)
        return NULL;
    inventory->food = 10;
    inventory->linemate = 0;
    inventory->deraumere = 0;
    inventory->sibur = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->thystame = 0;
    return inventory;
}

client_t *init_client(void)
{
    client_t *client = my_malloc(sizeof(client_t), NULL);

    if (!client)
        return NULL;
    client->fd = 0;
    client->id = 0;
    client->port = 0;
    client->socket = 0;
    client->team_name = NULL;
    client->is_in_team = false;
    client->is_already_connected = false;
    client->x = 0;
    client->y = 0;
    client->orientation = 0;
    client->inventory = init_inventory();
    init_list(&(client->commands));
    return client;
}

server_t *init_server(void)
{
    server_t *server = my_malloc(sizeof(server_t), NULL);

    if (!server)
        return NULL;
    server->port = 0;
    server->width = 0;
    server->height = 0;
    server->teams_names = NULL;
    server->clients_nb = 0;
    server->freq = (server->freq) ? 0 : 100;
    server->max_fd = 0;
    server->fd = 0;
    server->ip = NULL;
    server->tv.tv_sec = 0;
    server->tv.tv_usec = 0;
    server->addrlen = 0;
    server->all_fd = NULL;
    server->command_time_execution = 0;
    return server;
}
