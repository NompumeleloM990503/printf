#include "main.h"

/**
 * get_precision - Calculates the precision.
 * @format: Formatted string in which the arguments are
 * to be printed.
 * @i: List of arguments to be printed.
 * @list: The list of the progam's arguments.
 * Return: The precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current = *i + 1;
	int precision = -1;

	if (format[current] != '.')
		return (precision);

	precision = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			precision *= 10;
			precision += format[current] - '\0';
		}
		else if (format[current] == '*')
		{
			current++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (precision);
}
