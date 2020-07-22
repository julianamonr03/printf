#include "holberton.h"
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
/**
 * _printf - Prints anything
 * @format: is a character string.
 * Return: # of character printed.
 */
int _printf(const char *format, ...)
{
	va_list args;

	int i = 0;
	int j = 0;
	char *str;
	char tmp[2];
	char buf[2048];

	va_start(args, format);

	if (!format)
	{
		return (-1);
	}
	for (i = 0; format && format[i]; i++, j++)
	{
		if (format[i] != '%')
		{
			buf[j] = format[i];
		}
		else
		{
			if (!format || format[i] == '\n' || format[i] == '\0' ||
			 (format[i] == '%' && !format[i + 1]))
			{
				return (-1);
			}
			str = get_format(format[++i], args);
			if (str != NULL)
			{
				_strcpy(buf + j, str);
				j += _strlen(str) - 1;
				if (format[i + 1] == 'c' && str[0] == '\0')
				{
					j++;
				}
			}
			else
			{
				tmp[0] = '%';
				tmp[1] = format[i];
				_strcpy(buf + j, tmp);
				j += 1;
			}
		}
	}
	buf[j] = '\0';
	write(1, buf, j);
	return (j);
}
/**
 * *_strcpy - copies string pointed to by src
 * @dest: character pointer
 * @src: character source
 *Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
/**
 * _strlen - returns the length of a string
 * @s: character
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		i++;
	}
	return (i);
}
