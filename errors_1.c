/*
 * File: errors_1.c
 * Auth: NanaaAsare
 *       all the best in this project DoHardThings
 */

#include "monty.h"

int milage_error(void);
int malloc_error(void);
int t_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int non_int_error(unsigned int line_number);

/**
 * milage_error - Prints milage error messages.
 *
 */
int milage_error(void)
{
	yprinty(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 */
int malloc_error(void)
{
	yprinty(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * t_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 */
int t_open_error(char *filename)
{
	yprinty(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	yprinty(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 */
int non_int_error(unsigned int line_number)
{
	yprinty(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}