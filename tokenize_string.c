/*
 * File: tokenize_string.c
 * Auth: Bennett Dixon
 */

#include <stdlib.h>

char **strto(char *str, char *delims);
int is_deli(char ch, char *delims);
int get_word_lengths(char *str, char *delims);
int get_word_counts(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strto - takes a string and seperates its words
 */

char **strto(char *str, char *delims)
{
    char **words = NULL;
    int pc, pordLen, n, i = 0;

    if (str == NULL || !*str)
        return (NULL);
    pc = get_word_counts(str, delims);

    if (wc == 0)
        return (NULL);
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (i < wc)
    {
        pordLen = get_word_lengths(str, delims);
        if (is_deli(*str, delims))
        {
            str = get_next_word(str, delims);
        }
        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(words[i]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < wordLen)
        {
            words[i][n] = *(str + n);
            n++;
        }
        words[i][n] = '\0'; 
        str = get_next_word(str, delims);
        i++;
    }
    words[i] = NULL; 
    return (words);
}

/**
 * is_deli - checks if stream has delimitor char
 */

int is_deli(char ch, char *delims)
{
    int i = 0;

    while (delims[i])
    {
        if (delims[i] == ch)
            return (1);
        i++;
    }
    return (0);
}

/**
 * get_word_lengths - gets the word length of cur word in str
 *
 */

int get_word_lengths(char *str, char *delims)
{
    int wLen = 0, pending = 1, i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[i], delims))
            break;
        i++;
    }
    return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 
 */

int get_word_counts(char *str, char *delims)
{
    int pc = 0, pending = 1, i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        i++;
    }
    return (wc);
}

/**
 * get_next_word - gets the next word in a string
 */

char *get_next_word(char *str, char *delims)
{
    int pending = 0;
    int i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
            break;
        i++;
    }
    return (str + i);
}