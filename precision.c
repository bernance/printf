#include "main.h"

/**
* get_precision - a function that  gets the precision from the format string
* @str: the format string
* @params: the parameters struct
* @ap: the argument pointer
* Return: a new pointer
*/

char *get_precision(char *str, params_t *params, va_list ap)
{
	int i = 0;

	if (*str != '.')
		return (str);
	str++;
	if (*str == '*')
	{
		i = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			i = i * 10 + (*str++ - '0');
	}
	params->precision = i;
	return (str);
}
