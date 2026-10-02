/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** add_player_in_tem
*/

#include "server.h"

static void add_new_client_int_team(server_t *server, client_t *client,
char *cmd, team_t *team)
{
    if (!server || !client || !cmd || !team)
        return;
    if (team->nb_players >= team->max_clients) {
        dprintf(client->fd, "ko\n");
        return;
    }
    team->nb_players++;
    client->team_name = team->name;
    dprintf(client->fd, "%d\n", team->max_clients - team->nb_players);
    dprintf(client->fd, "%d %d\n", server->width, server->height);
    client->is_already_connected = true;
    pnw(server, client);
    return;
}

static void check_if_client_is_already_in_team(server_t *server,
client_t *client, char *cmd, team_t *team)
{
    if (!server || !client || !cmd || !team)
        return;
    for (int i = 1; server->teams_names[i]; i++) {
        if (server->teams_names[i] == client->team_name) {
            dprintf(client->fd, "ko\n");
            client->is_in_team = true;
            return;
        }
    }
    add_new_client_int_team(server, client, cmd, team);
}

static void check_if_team_is_full(server_t *server, client_t *client,
char *cmd, team_t *team)
{
    if (!server || !client || !cmd)
        return;
    if (client->is_in_team == true) {
        dprintf(client->fd, "ko\n");
        return;
    }
    for (int i = 0; server->teams_names[i]; i++) {
        if (my_strcmp(server->teams_names[i], cmd) == 0) {
            team->name = server->teams_names[i];
            break;
        } else {
            dprintf(client->fd, "ko\n");
            return;
        }
    }
    if (!team || team->nb_players >= team->max_clients) {
        dprintf(client->fd, "ko\n");
        return;
    }
    check_if_client_is_already_in_team(server, client, cmd, team);
}

void check_if_team_exist(server_t *server, client_t *client, char *cmd,
team_t *team)
{
    if (!server || !client || !cmd)
        return;
    for (int i = 0; server->teams_names[i]; i++) {
        if (my_strcmp(server->teams_names[i], cmd) == 0) {
            team->name = server->teams_names[i];
            break;
        }
    }
    if (!team) {
        dprintf(client->fd, "ko\n");
        return;
    }
    check_if_team_is_full(server, client, cmd, team);
}
