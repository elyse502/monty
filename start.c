#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;		/* Global var declaration */

/**
 * main - Entry point.
 * @argv: List of arguments passed to our program.
 * @argc: Amount of argments.
 *
 * Return: Nothing.
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1;  /* struct defined in monty.h line 61*/
	if (argc != 2)
		error_usage(); /* def in line 82 */

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);  /* def in line 68 */

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - Prints file error message and exits.
 * @argv: Argv given by main().
 *
 * Desc: Print msg if  not possible to open the file.
 * Return: Nothing.
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - Prints usage message and exits.
 *
 * Desc: If user does not give any file or more than
 * one argument to your program.
 *
 * Return: Nothing.
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

