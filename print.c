#include "shell.h"

/**
* _putchar - writes  character c to standard out,
* @c: The character to print,
*
* Return: On success returns 1,
* On error, -1 will return and errno set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_s - prints a string
* @s: string to  printed
*
* Return: num of characters printed
*/
int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

