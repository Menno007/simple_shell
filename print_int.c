#include "main.h"
/**
 * print_int - bla
 *
 * @integer: the integer him self
 *
 * Return: num of chars
 */
int print_int(int integer)
{
	char buffer[32];
	int length = 0;
	int NumOfChars = 0;
	int i;

	if (integer == INT_MIN)
	{
		NumOfChars += write(1, "-2147483648", 11);
		return (NumOfChars);
	}
	if (integer < 0)
	{
		NumOfChars += print_char('-');
		integer = -integer;
	}

	do {
		buffer[length++] = integer % 10;
		integer /= 10;
	} while (integer > 0);

	for (i = (length - 1); i >= 0; i--)
	{
		NumOfChars += print_char('0' + buffer[i]);
	}
	return (NumOfChars);
}
