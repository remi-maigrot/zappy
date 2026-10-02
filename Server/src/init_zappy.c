/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_zappy
*/

#include "server.h"

void add_teams(char **argv, int index, server_t *server)
{
    int i = 0;

    if (!argv || !server)
        return;
    while (argv[index][0] != '-' || argv[index] == NULL) {
        server->teams_names = realloc(server->teams_names, sizeof(char *)
        * (i + 1));
        server->teams_names[i] = my_malloc(sizeof(char) *
        my_strlen(argv[index]) + 1, argv[index]);
        my_strcpy(server->teams_names[i], argv[index]);
        i++;
        index++;
    }
    server->teams_names[i - 1] = NULL;
}

int get_team_index(server_t *server, char *team_name)
{
    if (!server || !team_name)
        return -1;
    for (int i = 0; server->teams_names[i]; i++) {
        if (my_strcmp(server->teams_names[i], team_name) == 0)
            return i;
    }
    return -1;
}

int init_zappy(char **argv)
{
    server_t *server = init_server();
    client_t clients[MAX_CLIENTS] = {0};

    if (!server || !argv)
        return 84;
    for (int index = 1; argv[index]; index++) {
        if (argv[index][0] == '-')
            stocking_args(argv, index, server);
    }
    if (start_server_zappy(server, clients) == 84)
        return 84;
    return 0;
}
