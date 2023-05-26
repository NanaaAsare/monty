/*
 * File: monty_funcs_2.c
 * Auth: NanaaAsare

 */

#include "monty.h"

void monty_adds(stack_t **stack, unsigned int line_number);
void monty_subs(stack_t **stack, unsigned int line_number);
void monty_divs(stack_t **stack, unsigned int line_number);
void monty_muls(stack_t **stack, unsigned int line_number);
void monty_mods(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 */
void monty_adds(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "add"));
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    monty_pops(stack, line_number);
}

/**
 * monty_sub - Subtracts the second value from the top of
 */
void monty_subs(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "sub"));
        return;
    }

    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pops(stack, line_number);
}

/**
 * monty_div - Divides the second value from the top of
 */
void monty_divs(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "div"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pops(stack, line_number);
}

/**
 * monty_mul - Multiplies the second value from the top of
 */
void monty_muls(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mul"));
        return;
    }

    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pops(stack, line_number);
}

/**
 * monty_mod - Computes the modulus of the second value from the
 */
void monty_mods(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mod"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pops(stack, line_number);
}