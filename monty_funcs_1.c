/**
 * File: monty_funcs_1.c
 * Auth: NanaaAsare
*/

#include "monty.h"

void monty_pushs(stack_t **stack, unsigned int line_number);
void monty_palls(stack_t **stack, unsigned int line_number);
void monty_pints(stack_t **stack, unsigned int line_number);
void monty_pops(stack_t **stack, unsigned int line_number);
void monty_swaps(stack_t **stack, unsigned int line_number);

/**
 * monty_pushs - Pushes a value to a stack_t linked list.
 */
void monty_pushs(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp, *new;
    int i;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        set_op_tok_error(malloc_error());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_error(no_int_error(line_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_error(no_int_error(line_number));
            return;
        }
    }
    new->n = atoi(op_toks[1]);

    if (check_mode(*stack) == STACK) 
    {
        tmp = (*stack)->next;
        new->prev = *stack;
        new->next = tmp;
        if (tmp)
            tmp->prev = new;
        (*stack)->next = new;
    }
    else /* QUEUE mode insert at end */
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        new->prev = tmp;
        new->next = NULL;
        tmp->next = new;
    }
}

/**
 * monty_palls - Prints the values of a stack_t linked list.
 */
void monty_palls(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 */
void monty_pints(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pint_error(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pops - Removes the top value element of a stack_t linked list.
 */
void monty_pops(stack_t **stack, unsigned int line_number)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pop_error(line_number));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * monty_swaps - Swaps the top two value elements of a stack_t linked list.
 */
void monty_swaps(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "swap"));
        return;
    }

    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}