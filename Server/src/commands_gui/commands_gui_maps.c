/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** commands_maps
*/

#include "server.h"

void msz(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    if (!game_info || !cmd)
        return;
    if (server->width == 0 || server->height == 0)
        return;
    dprintf(client->fd, "msz %d %d\n", server->width, server->height);
}

void bct(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    int x = 0;
    int y = 0;

    if (!server || !game_info || !cmd)
        return;
    if (cmd[1] == NULL || cmd[2] == NULL)
        return;
    x = atoi(cmd[1]);
    y = atoi(cmd[2]);
    dprintf(client->fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    game_info->map[y][x].food, game_info->map[y][x].deraumere,
    game_info->map[y][x].linemate, game_info->map[y][x].mendiane,
    game_info->map[y][x].phiras, game_info->map[y][x].sibur,
    game_info->map[y][x].thystame);
}

void mct(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    if (!server || !game_info || !cmd)
        return;
    for (int i = 0; i < server->height; i++) {
        for (int j = 0; j < server->width; j++) {
            dprintf(client->fd, "bct %d %d %d %d %d %d %d %d %d\n", j, i,
            game_info->map[i][j].food,
            game_info->map[i][j].deraumere,
            game_info->map[i][j].linemate,
            game_info->map[i][j].mendiane,
            game_info->map[i][j].phiras,
            game_info->map[i][j].sibur,
            game_info->map[i][j].thystame);
        }
    }
}

void tna(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    if (!server || !game_info || !cmd)
        return;
    for (int i = 0; server->teams_names[i]; i++) {
        dprintf(client->fd, "tna %s\n", server->teams_names[i]);
    }
}
