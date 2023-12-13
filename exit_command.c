#include "shell.h"

/**
 * exits - shell is exited with or without a return of status n
 * @arv: array of words of the inputed line
 */
void exits(char **arv)
{
	int i, n;

	if (arv[1])

{
	n = _atoi(arv[1]);
	if (n <= -1)
	n = 2;
	free_arv(arv);
	exit(n);
}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * _atoi - it convert a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
{
	if (s[i] == '-')
{
	sign = sign * (-1);
}
	i++;
}
	while ((s[i] >= '0') && (s[i] <= '9'))
{
	integer = (integer * 10) + (sign * (s[i] - '0'));
	i++;
}
	return (integer);
}

/**
 * env - prints the current environment
 * @arv: array of arguments
 */
void env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
{
	_pchar(environ[i]);
	_pchar("\n");
}

}

/**
 * _setenv - a new environment variable initialized or modify an existing one
 * @arv: array of inputed words
 */
void _setenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
{
	perror(_getenv("_"));
}

	for (i = 0; environ[i]; i++)
{
	j = 0;
	if (arv[1][j] == environ[i][j])
{
	while (arv[1][j])
{
	if (arv[1][j] != environ[i][j])
	break;

	j++;
}
	if (arv[1][j] == '\0')
{
	k = 0;
	while (arv[2][k])
{
	environ[i][j + 1 + k] = arv[2][k];
	k++;
}
	environ[i][j + 1 + k] = '\0';
}
}
}
	if (!environ[i])
{

	environ[i] = _concatenate(arv[1], "=", arv[2]);
	environ[i + 1] = '\0';

}
}

/**
 * _unsetenv - an environment variable is removed
 * @arv: array of inputed words
 */
void _unsetenv(char **arv)
{
	int i, j;

	if (!arv[1])
{
	perror(_getenv("_"));
}
	for (i = 0; environ[i]; i++)
{
	j = 0;
	if (arv[1][j] == environ[i][j])
{
	while (arv[1][j])
{
	if (arv[1][j] != environ[i][j])
	break;

	j++;
}
	if (arv[1][j] == '\0')
{
	free(environ[i]);
	environ[i] = environ[i + 1];
	while (environ[i])
{
	environ[i] = environ[i + 1];
	i++;
}
}
}
}
}
