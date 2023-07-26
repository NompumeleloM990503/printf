#include "main.h"

/**
 * get_width - Calcualtes the width for printing.
 * @format: Formatte string in which the arguments
 * are to be printed.
 * @i: The list of arguments to be printed.
 * @list: List of arguments (program).
 * Return: Width
 */
int get_width(const char *format, int *i, va_list list)
{
	int current;
	int width = 0;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '\0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (width);
}
