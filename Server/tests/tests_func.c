/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tests_func
*/

#include "server.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

// !  removed function
/* Test(str_tab, test_str_tab)
{
    char *str = "test test test";
    char **tab = str_tab(str, ' ');

    cr_assert_str_eq(tab[0], "test");
    cr_assert_str_eq(tab[1], "test");
    cr_assert_str_eq(tab[2], "test");
} */

Test(my_malloc, test_my_malloc)
{
    char *str = "test";
    char *str2 = my_malloc(sizeof(char) * (my_strlen(str) + 1), str);

    cr_assert_str_eq(str2, "test");
}

Test(my_strcmp, test_my_strcmp)
{
    char *str = "test";
    char *str2 = "test";

    cr_assert_eq(my_strcmp(str, str2), 0);
}


/* Test(my_strcmp, test_my_strcmp2)
{
    char *str = NULL;
    char *str2 = "test";

    cr_assert_eq(my_strcmp(str, str2), -1);
} */

Test(my_strcpy, test_my_strcpy)
{
    char *str = "test";
    char *str2 = my_malloc(sizeof(char) * (my_strlen(str) + 1), NULL);

    str2 = my_strcpy(str2, str);
    cr_assert_str_eq(str2, "test");
}

Test(my_strcpy, test_my_strcpy2)
{
    char *str = NULL;
    char *str2 = my_malloc(sizeof(char) * (my_strlen(str) + 1), NULL);

    str2 = my_strcpy(str2, str);
    cr_assert_eq(str2, NULL);
}

Test(my_strcpy, test_my_strcpy3)
{
    char *str = "test";
    char *str2 = NULL;

    str2 = my_strcpy(str2, str);
    cr_assert_eq(str2, NULL);
}

Test(my_strcpy, test_my_strcpy4)
{
    char *str = NULL;
    char *str2 = NULL;

    str2 = my_strcpy(str2, str);
    cr_assert_eq(str2, NULL);
}

Test(my_strlen, test_my_strlen)
{
    char *str = "test";

    cr_assert_eq(my_strlen(str), 4);
}

Test(my_strlen, test_my_strlen2)
{
    char *str = "";

    cr_assert_eq(my_strlen(str), 0);
}


