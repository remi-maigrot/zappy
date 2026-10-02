/*
** EPITECH PROJECT, 2022
** lib
** File description:
** str_word_array from stumper 01
*/

#include <stdlib.h>
#include "my.h"

static int strwa_array_size(const char *str, const char *sep)
{
    int words = 1;
    int sep_len = 0;
    int str_len = 0;

    if (str == NULL || sep == NULL)
        return 0;
    sep_len = my_strlen(sep);
    str_len = my_strlen(str);
    for (int i = 0; i < str_len; i++)
        for (int j = 0; j < sep_len; j++)
            words += my_charcmp(str[i], sep[j]);
    return words;
}

static int strwa_check_this_char(str_to_words_array_t *w_a)
{
    int new_word = 0;
    int skip_char = 0;
    int sep_l = 0;

    if (w_a->sep == NULL)
        return 84;
    sep_l = my_strlen(w_a->sep);
    for (int i = 0; i < sep_l; i++) {
        strwa_check_char_two(w_a, &skip_char, &new_word, i);
    }
    if (new_word != 0 && w_a->str[1] != '\0' && skip_char != 0)
        return 1;
    if (skip_char != 0)
        return 2;
    return 0;
}

static int strwa_engine(str_to_words_array_t *w_a)
{
    switch (strwa_check_this_char(w_a)) {
        case 84: return 84; break;
        case 0: w_a->words[w_a->current_word][w_a->current_in_word] =
                w_a->str[0];
                w_a->current_in_word++;
                break;
        case 1: w_a->current_in_word = 0;
                w_a->current_word++;
                w_a->words[w_a->current_word] =
                my_malloc(my_strlen(w_a->str) + 1, NULL);
                if (w_a->words[w_a->current_word] == NULL)
                    return 84;
                break;
        case 2: w_a->current_in_word = 0;
                break;
    }
    return 0;
}

static str_to_words_array_t *strwa_init(const char *str,
const char separators[])
{
    str_to_words_array_t *words_arr =
    my_malloc(sizeof(str_to_words_array_t), NULL);
    int array_size = strwa_array_size(str, separators);

    if (str == NULL || separators == NULL || words_arr == NULL)
        return NULL;
    strwa_init_two(str, separators, words_arr);
    words_arr->words = my_malloc(sizeof(char*) * (array_size + 1), NULL);
    for (int i = 0; i < array_size; i++)
        words_arr->words[i] = NULL;
    if (words_arr->words == NULL)
        return NULL;
    words_arr->words[0] = my_malloc(words_arr->str_length + 1, NULL);
    if (words_arr->words[0] == NULL)
        return NULL;
    return words_arr;
}

char **my_str_to_words_array(const char *str, const char separators[])
{
    str_to_words_array_t *words_arr = strwa_init(str, separators);
    char **words = NULL;
    int words_size_allocated = strwa_array_size(str, separators);

    if (words_arr == NULL)
        return NULL;
    for (; words_arr->str[0] != '\0'; words_arr->str++)
        if (strwa_engine(words_arr) == 84)
            return NULL;
    for (int i = 0; i <= words_size_allocated; i++)
        if (words_arr->words[words_arr->current_word] == '\0') {
            free(words_arr->words[words_arr->current_word]);
            words_arr->words[words_arr->current_word] == NULL;
        }
    for (int i = 0; i < words_arr->str_length; i++)
        str--;
    words = words_arr->words;
    free(words_arr);
    return words;
}
