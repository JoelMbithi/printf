#include "main.h"

unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_c - Converts an argument to unsigned char and stores it to
 * to a buffer contained in a structure.
 * @args: va_list pointing to arguments to bo converted.
 * @flags: Flag modifiers.
 * @wid: A width specifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: Buffer_t struct cont a char array.
 *
 * Return: NUmber of bytes stored to buffer
 */
unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	ret += print_width(output, ret, flags, wid);
	ret += _memcpy(output, &c, 1);
	ret += print_neg_width(output, ret, flag, wid);

	return (ret);
}

/**
 * convert_percent -Stores a percent sign to a buffer contained in struct
 *
 * @args: Va_list of args to convert.
 * @flags: Flag modifier.
 * @wid: Width modifier.
 * @prec: precision modifier
 * @len: Length modifier.
 * @output: Buffer_t struct containing character array.
 *
 * Return: Number of bytes stored to buffer (always 1).
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)len;

	ret += print_width(output, ret, flags, wid);
	ret += _memcpy(output, &percent, 1);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_p -Converts the address of ana argument to hex
 * and stores it to a buffer contained in a struct.
 *
 * @args: A va_list pointing to the arguments to be converted.
 * @flags: flag modifier
 * @wid: width modifier
 * @prec: precision modifier
 * @len: Length modifier
 * @output: buffer_t struct containing  character array.
 *
 * Return: Number of bytes stored to buffer.
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;
	ret += convert_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	ret += print_neg_width(output, ret flags, wid);
}
