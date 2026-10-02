/*
** EPITECH PROJECT, 2021
** lib
** File description:
** function
*/

#include <unistd.h>

char **my_create_tab(const int nb_line, const int nb_char)
{
    char **tab = NULL;
    int i = 0;

    if (nb_line <= 0 || nb_char <= 0)
        return tab;
    if ((tab = my_malloc(sizeof(char*) * nb_line, NULL)) == NULL)
        return NULL;
    for (i = 0; i < nb_line; i++)
        if ((tab[i] = my_malloc(sizeof(char) * nb_char + 1, NULL)) == NULL)
            return NULL;
    return tab;
}
