#ifndef _monty_h
#define _monty_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;


typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instructions_s - opcode and its function
 */
typedef struct instructions_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instructions_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void freed_stack(stack_t **stack);
int inits_stack(stack_t **stack);
int checkd_mode(stack_t *stack);
void freed_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void monty_pushs(stack_t **stack, unsigned int line_number);
void monty_palls(stack_t **stack, unsigned int line_number);
void monty_pints(stack_t **stack, unsigned int line_number);
void monty_pops(stack_t **stack, unsigned int line_number);
void monty_swaps(stack_t **stack, unsigned int line_number);
void monty_adds(stack_t **stack, unsigned int line_number);
void monty_nops(stack_t **stack, unsigned int line_number);
void monty_subs(stack_t **stack, unsigned int line_number);
void monty_divs(stack_t **stack, unsigned int line_number);
void monty_muls(stack_t **stack, unsigned int line_number);
void monty_mods(stack_t **stack, unsigned int line_number);
void monty_ptchar(stack_t **stack, unsigned int line_number);
void monty_pstrs(stack_t **stack, unsigned int line_number);
void monty_rotls(stack_t **stack, unsigned int line_number);
void monty_rotrs(stack_t **stack, unsigned int line_number);
void monty_stacks(stack_t **stack, unsigned int line_number);
void monty_queues(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int milage_error(void);
int malloc_error(void);
int t_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int myhort_stack_error(unsigned int line_number, char *op);
int dived_error(unsigned int line_number);
int ptchar_error(unsigned int line_number, char *message);

#endif