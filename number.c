#include "main.h"

/**
* print_address_range - prints the value of a range of char addresses
* @start: starting address
* @stop: stopping address
* @except: except address
*
* Return: number of chars printed
*/
int print_address_range(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
* print_rev - prints a string in reverse
* @ap: string
* @params: the parameters struct
*
* Return: number of chars printed
*/
int print_rev(va_list ap, params_t *params)
{
	int length, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
* print_rot13 - prints a string in rot13
* @ap: string
* @params: the parameters struct
*
* Return: number of char printed
*/
int print_rot13(va_list ap, params_t *params)
{
	int b;
	int index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	b = 0;
	index = 0;
	while (a[b])
	{
		if ((a[b] >= 'A' && a[b] <= 'Z')
		    || (a[b] >= 'a' && a[b] <= 'z'))
		{
			index = a[b] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[b]);
		b++;
	}
	return (count);
}
