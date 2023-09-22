#include "main.h"

/*
 * print_unsigned - print an unsigned number 
 * @type:list a arguments
 * @buffer:Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * Return:Number of chars printed
 */

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED (width);

	num = convert_size_unsignd(num, size);

	if (num== 0)
		buffer [i--] = '\0';
	buffer[BUFF_SIZE -1] = '\0';

	while (num > 0 )
	{
		buffer[i--] = map_to[num % 16]
			num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	 return (write_unsigned(0, i, buffer, flags, width, precision ,size));
}
