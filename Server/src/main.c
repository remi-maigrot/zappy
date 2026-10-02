/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include "server.h"

int main(int argc, char **argv)
{
    printf("Welcome to Zappy!\n");
    if (argc == 2 && my_strcmp(argv[1], "-help") == 0) {
        usage();
        return 0;
    }
    if (init_zappy(argv) == 84)
        return 84;
    return 0;
}
