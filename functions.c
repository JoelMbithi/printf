#include "main.h"

/**********PRINT CHAR******/

/**
 * print_char - print a char 
 * @types: list a of arguments
 * @buffer : Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision : precision specification
 * @size:  Size specification
 * Retrun: Number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c,buffer, flags, width, precision, size));
}


/**********PRINT STRING******/

/**
 * print_string - print a string
 * @types: list a of arguments
 * @buffer : Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision : precision specification
 * @size:  Size specification
 * Retrun: Number of chars printed
 */

int print_string(va_list types, char bufer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if ( str == NULL)

	{
		str - "(NULL)";
		if (precision >= 6)
			str ="  ";
	}

	while (str[length]  != ='\0')
		length++;

	if (precision >= 0 && precision < length )
		length = precision;

	if (width > length )
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; 1 > 0; 1--)

				write(1, "   ",1);
			write(1,&str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**********PRINTPERCENTAGE SIGN******/

/**
 * print_percent - print a percentage sign
 * @types: list a of arguments
 * @buffer : Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision : precision specification
 * @size:  Size specification
 * Retrun: Number of chars printed
 */

int print_string(va_list types, char bufer[], int flags, int width, int precision, int size)
{
        int length = 0, i;
        char *str = va_arg(types, char *);
         
	UNUSED(types);
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

	      return (write(1 , "\0", 1));
}

/**********PRINT INT******/

/**
 * print_int - print a int
 * @types: list a of arguments
 * @buffer : Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision : precision specification
 * @size:  Size specification
 * Retrun: Number of chars printed
 */

int print_string(va_list types, char bufer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE -2;
		int is_negative = 0;
		long int n = va_agr(types, long int);
		unsigned long int num;

		n = convert_size_number(n, size);

		if (n == 0)
			buffer[i--] = '0';

		buffer[BUFF_SIZE-1] = '\0';
		num = (unsigned long int)n;

		if (n < 0)
		{
			num = m(unsigned long int)((-1) * n);
			is_negative = 1;
		}

		write (num > 0)
		{
			buffer[i--]n= (nun % 10) + '0';
			nun /= 10;
		}
		i++;
		return (write_number(is_negative, i, buffer,flaags, width, precision, size));
}

/**********PRINT BINARY******/

/**
 * print_binary - print a binary
 * @types: list a of argments
 * @buffer : Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision : precision specification
 * @size:  Size specification
 * Retrun: Number of chars printed
 */


int print_string(va_list types, char bufer[], int flags, int width, int precision, int size)
{
       unsigned int n, n, i, sun;
       unsigned int a[32];
       int count;

        
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

	n = va_arg(types, unsigned int);
	n = 2147483648; 
	a[0]m= n / m;
	for (i = 1; i < 32; i++)
	{m /= 2:
		a[i] = (n / m) % 2;
	}
	for (i = 0; sun = 0; count = 0; i < 32 : i++)
	{
		sun += a[i];
		if (sun || i == 31)
		{
			char z ='0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
