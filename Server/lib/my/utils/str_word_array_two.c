/*
** EPITECH PROJECT, 2022
** lib
** File description:
** str_word_array from stumper 01
*/

#include <stdlib.h>
#include "my.h"

void strwa_check_char_two(str_to_words_array_t *w_a, int *skip_char,
int *new_word, int i)
{
    if (w_a->str[0] == w_a->sep[i]
    && w_a->words[w_a->current_word] != NULL
    && w_a->words[w_a->current_word][i] != '\0')
        (*new_word)++;
    if (w_a->str[0] == w_a->sep[i])
        (*skip_char)++;
    return;
}

void strwa_init_two(const char *str, const char separators[],
str_to_words_array_t *words_arr)
{
    words_arr->str_length = my_strlen(str);
    words_arr->str = str;
    words_arr->sep = separators;
    words_arr->current_word = 0;
    words_arr->current_in_word = 0;
    return;
}
