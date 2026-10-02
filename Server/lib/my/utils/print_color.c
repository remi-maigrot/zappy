/*
** EPITECH PROJECT, 2021
** my lib
** File description:
** print of a certain color
*/

#include <stdlib.h>

#include "my.h"

void write_white(const char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[37m%s\x1B[0m", str);
}

void write_blue(const char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[34m%s\x1B[0m", str);
}

void write_green(const char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[32m%s\x1B[0m", str);
}

void write_cyan(const char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[36m%s\x1B[0m", str);
}

void write_red(const char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[31m%s\x1B[0m", str);
}
