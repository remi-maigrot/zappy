/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** find_commands
*/

#include "server.h"

static const command_t ai_commands[] = {
    // {.command = "Forward", .ptr = &forward_cmd},
    // {.command = "Right", .ptr = &right_cmd},
    // {.command = "Left", .ptr = &left_cmd},
    // {.command = "Look", .ptr = &look_cmd},
    // {.command = "Inventory", .ptr = &inventory_cmd},
    // {.command = "Broadcast", .ptr = &broadcast_cmd},
    // {.command = "Connect_nbr", .ptr = &connect_nbr_cmd},
    // {.command = "Fork", .ptr = &fork_cmd},
    // {.command = "Eject", .ptr = &eject_cmd},
    // {.command = "Take", .ptr = &take_cmd},
    // {.command = "Set", .ptr = &set_cmd},
    // {.command = "Incantation", .ptr = &incantation_cmd},
    {.command = NULL, .ptr = NULL}
};

static const command_t gui_commands[] = {
    {.command = "msz", .ptr = &msz},
    {.command = "bct", .ptr = &bct},
    {.command = "mct", .ptr = &mct},
    {.command = "tna", .ptr = &tna},
    {.command = "ppo", .ptr = &ppo},
    {.command = "plv", .ptr = &plv},
    {.command = "pin", .ptr = &pin},
    {.command = "sgt", .ptr = &sgt},
    {.command = "sst", .ptr = &sst},
    {.command = NULL, .ptr = NULL}
};

const command_t *is_ai_commands(char **cmd)
{
    printf("ia cmd[0] = %s\n", cmd[0]);
    for (int index = 0; ai_commands[index].command; index++) {
        if (my_strcmp(ai_commands[index].command, cmd[0]) == 0)
            return (&ai_commands[index]);
    }
    return (NULL);
}

const command_t *is_gui_commands(char **cmd)
{
    printf("gui cmd[0] = %s\n", cmd[0]);
    for (int index = 0; gui_commands[index].command; index++) {
        if (strcmp(gui_commands[index].command, cmd[0]) == 0)
            return (&gui_commands[index]);
    }
    return (NULL);
}
