/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command_gui_player
*/

#include "server.h"

void pin(__attribute__((unused)) server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    client_t *player = NULL;

    if (!game_info)
        return;
    if (cmd[1] == NULL)
        return;
    player = get_client_by_id(client, atoi(cmd[1]));
    if (player == NULL)
        return;
    dprintf(client->fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
    player->id,
    player->x, player->y, player->inventory->food,
    player->inventory->linemate, player->inventory->deraumere,
    player->inventory->sibur, player->inventory->mendiane,
    player->inventory->phiras, player->inventory->thystame);
}

void plv(__attribute__((unused)) server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    client_t *player = NULL;

    if (!game_info)
        return;
    if (cmd[1] == NULL)
        return;
    player = get_client_by_id(client, atoi(cmd[1]));
    if (player == NULL)
        return;
    dprintf(client->fd, "plv %d %d\n", player->fd, player->level);
}

void ppo(__attribute__((unused)) server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    client_t *player = NULL;

    if (!game_info)
        return;
    if (cmd[1] == NULL)
        return;
    player = get_client_by_id(client, atoi(cmd[1]));
    if (player == NULL)
        return;
    dprintf(client->fd, "ppo %d %d %d %d\n", player->fd, player->x,
    player->y, player->orientation);
}
