#include "main.h"

/**
 * get_size - Calculates the size to cast the argument.
 * @format: Formatted string in which the
 * output is to be printed.
 * @i: The list of arguments to be printed.
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
	int current = *i + 1;
	int size = 0;

	if (format[current] == '|')
		size = S_LONG;
	if (format[current] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current - 1;
	else
		*i = current;

	return (size);
}
