/*
 * File: errors_2.c
 * Auth: NanaaAsare
 */

#include "monty.h"

int myhort_stack_error(unsigned int line_number, char *op);
int dived_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int dived_error(unsigned int line_number);
int ptchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Prints pop error messages for empty stacks.
 */
int pop_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 */
int mint_error(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * myhort_stack_error - Prints monty function error messages
 */
int myhort_stack_error(unsigned int line_number, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
    return (EXIT_FAILURE);
}

/**
 * dived_error - Prints divied error messages for division by 0.
 */
int dived_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * ptchar_error - Prints pchar error messages for empty stacks
 */
int ptchar_error(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
    return (EXIT_FAILURE);
}