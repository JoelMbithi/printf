#include "main.h"

int run_printf(const char *format, va_list args, buffer_t *output);

/**
 * run_printf - Reads thru format string.
 * @format: Character string to print
 * @output: A buffer_t containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: No of chars stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *, unsigned char,
			int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1, &tmp);
			len = handle_length(format + i + temp + 1);

			f = handle_specifiers(format + i + temp + 1);
		}
	}
}



/**
 * _printf - Outputs formatted string
 * @format: String to print
 *
 * Return: No of chars printed
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);

	output = init_buffer();

	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
