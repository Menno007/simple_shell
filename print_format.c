#include "main.h"
/**
 * print_format - handels %s and %c and %%
 *
 * @format: the fprmat saci..
 *
 * @args: the args list
 *
 * Return: numofchars
 */

int print_format(char format, va_list args)
{
	int NumOfChars = 0;
	char c, *s;

	while (format)
	{
		if (format == '\0')
			break;
		else if (format == 'c')
		{
			c = va_arg(args, int);
			NumOfChars += print_char(c);
		}
		else if (format == 's')
		{
			s = va_arg(args, char*);
			NumOfChars += print_string(s);
		}
		else if (format == '%')
		{
			NumOfChars += print_percent();
		}
		else
		{
			format++;
		}
		format++;
	}
	return (NumOfChars);
}
