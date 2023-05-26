/*
 * File: stack.c
 * Auth: NanaaAsare
 */

#include "monty.h"
#include <string.h>

void freed_stack(stack_t **stack);
int inits_stack(stack_t **stack);
int checkd_mode(stack_t *stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void freed_stack(stack_t **stack)
{
    stack_t *tmp = *stack;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

/**
 * inits_stack - Initializes a stack_t stack with beginning
 */
int inits_stack(stack_t **stack)
{
    stack_t *s;

    s = malloc(sizeof(stack_t));
    if (s == NULL)
        return (malloc_error());

    s->n = STACK;
    s->prev = NULL;
    s->next = NULL;

    *stack = s;

    return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 */
int checkd_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}