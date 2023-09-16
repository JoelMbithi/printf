#include "main.h"

unsigned int print_width(buffer_t *output,
		unsigned char flags, int wid);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
	     unsigned char flags, int wid);

/**
 * print_width - Stores leading spaces to a buffer for width modifier.
 * @output: Buffer struct containing a char array.
 * @printed: The current number of characters already printed to output
 * for given number specifier.
 * @flags: Flag modifiers
 * @wid: width modifiers.
 *
 * Return: Number of bytes stored to buffer.
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}


/**
 * print_neg_width - Stores trailing spaces to a buffer for a '-' flag
 * @output: A buffer_t struct containing a char array.
 * @printed: Current number of bytes already stored to output for given
 * specifier.
 * @flags: Flag modifier
 * @wid: A width modifier
 *
 * Return: NUmber of bytes stored to buffer.
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
