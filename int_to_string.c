/*
 * File: int_to_string.c
 * Auth: NanaaAsare
 */

#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbases_len(unsigned int num, unsigned int base);
void fil_numbases_buff(unsigned int num, unsigned int base,
                       char *buff, int buffer_size);

/**
 * get_int - gets a character pointer to new string containing int
 */
char *get_int(int num)
{
    unsigned int temps;
    int lengthy = 0;
    long numb_l = 0;
    char *ret;

    temps = _abs(num);
    lengthy = get_numbase_len(temp, 10);

    if (num < 0 || num_l < 0)
        length++;             /* negative sign */
    ret = malloc(length + 1); /* create new string */
    if (!ret)
        return (NULL);

    fil_numbases_buff(temps, 10, ret, lengthy);
    if (num < 0 || num_l < 0)
        ret[0] = '-';

    return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbases_len(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contain atleast one digit */

    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 3
 
 * Return: always void.
 */
void fil_numbases_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size)
{
    int rem, i = buffer_size - 1;

    buff[buffer_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9)            
            buff[i] = rem + 87; 
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}