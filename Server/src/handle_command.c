/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-evan.lacoste
** File description:
** handle_command
*/

#include "server.h"

const command_t *find_command(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return NULL;
    if (client->is_gui == true) {
        return is_gui_commands(cmd);
    } else {
        return is_ai_commands(cmd);
    }
    return (NULL);
}

static void check_client_type(char **tab, client_t *client, server_t *server,
team_t *team)
{
    if (!tab || !client)
        return;
    if (my_strcmp(tab[0], "GRAPHIC") == 0) {
        client->team_name = "GRAPHIC";
        client->is_gui = true;
    } else {
        check_if_team_exist(server, client, tab[0], team);
    }
    return;
}

void handle_command(server_t *server, client_t *client, game_info_t *game_info)
{
    team_t *team = init_team(server);
    const command_t *command = NULL;
    char buffer[1024];
    char **tab = NULL;
    int num_bytes = 0;

    if (!server || !client)
        return;
    num_bytes = read(client->fd, buffer, sizeof(buffer));
    if (num_bytes == -1)
        close(client->fd);
    tab = my_str_to_words_array(buffer, " \r\n");
    if (tab == NULL)
        return;
    if (client->is_already_connected == false) {
        check_client_type(tab, client, server, team);
        return;
    }
    command = find_command(server, client, tab);
    if (command == NULL)
        dprintf(client->fd, "Bad command\n");
    else {
        command->ptr(server, client, game_info, tab);
        push_node(&client->commands, buffer);
    }
}
