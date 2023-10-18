#include "main.h"

/**
* _printf - prints and input into the standard output
* @format: the format string
* Return: printed chars
*/

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list ap;
	char *s, *start;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = (char *)format; *s; s++)
	{
		init_params(&params, ap);
		if (*s != '%')/*checking for the format specifier*/
		{
			sum += _putchar(*s);
			continue;
		}
		start = s;
		s++;
		while (get_flag(s, &params))
		{
			s++; /* the next character */
		}
		s = get_width(s, &params, ap);
		s = get_precision(s, &params, ap);
		if (get_modifier(s, &params))
			s++;
		if (!get_specifier(s))
			sum += print_from_to(start, s,
					params.l_modifier || params.h_modifier ? s - 1 : 0);
		else
			sum += get_print_func(s, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
