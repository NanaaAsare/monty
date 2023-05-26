/*
 * File: monty_funcs_4.c
 * Auth: NanaaAsare
 */

#include "monty.h"

void monty_rotls(stack_t **stack, unsigned int line_number);
void monty_rotrs(stack_t **stack, unsigned int line_number);
void monty_stacks(stack_t **stack, unsigned int line_number);
void monty_queues(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 */
void monty_rotls(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;

    (void)line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 */
void monty_rotrs(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;

    (void)line_number;
}

/**
 * monty_stack - Converts a queue to a stack.
 */
void monty_stacks(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue..
 */
void monty_queues(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}