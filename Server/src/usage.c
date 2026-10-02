/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** usage
*/

#include "server.h"

void usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height");
    printf(" -n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tnameX is the name of the team X\n");
    printf("\tport is the port number\n");
    printf("\twidth is the width of the world\n");
    printf("\theight is the height of the world\n");
}
