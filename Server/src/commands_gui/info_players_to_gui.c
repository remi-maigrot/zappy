/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** info_players_to_gui
*/

#include "server.h"

void pnw(__attribute__((unused)) server_t *server, client_t *client)
{
    int id = client->id;
    int x = client->x;
    int y = client->y;
    int orientation = client->orientation;
    int level = client->level;
    char *team_name = client->team_name;

    for (int i = -1; i < MAX_CLIENTS; i++) {
        if (client[i].is_gui == true) {
            dprintf(client[i].fd, "pnw %d %d %d %d %d %s\n",
            id, x, y, orientation, level, team_name);
        }
    }
}
