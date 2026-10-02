/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_teams
*/

#include "server.h"

team_t *init_team(server_t *server)
{
    team_t *team = my_malloc(sizeof(team_t), NULL);

    if (!team)
        return NULL;
    team->name = NULL;
    team->max_clients = server->clients_nb;
    team->nb_players = 0;
    return team;
}
