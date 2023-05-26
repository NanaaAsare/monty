/*
 * File: monty_funcs_3.c
 * Auth: NanaaAsare
 */

#include "monty.h"

void monty_nops(stack_t **stack, unsigned int line_number);
void monty_ptchar(stack_t **stack, unsigned int line_number);
void monty_pstrs(stack_t **stack, unsigned int line_number);

/**
 * monty_nops - Does absolutely nothing for the Monty opcode 'nop'.
 */
void monty_nops(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * monty_ptchar - Prints the character in the top value
 */
void monty_ptchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_number,
                                     "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstrs - Prints the string contained in a stack_t linked list.
 */
void monty_pstrs(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)line_number;
}