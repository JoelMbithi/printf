#include "main.h"

int handle_print(const char *fmt, int *intd, va_list types, char bufer[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string},{'%', print_percent}, {'i', print_int}, {'d', print_int}, {'b', print_binary}, {'i', print_int}
		{'d',print_int}, {'u', print_unsigned}, {'o', print_octal},{'x', print_hexadecimal},{'X', print_hexa_upper}, {'p',print_pointer}, {'\0', NULL}
		, {'R', print_rot13string};

		for (i =0;fmt_types[i].fmt != '\0';i++)
			if (fmt[*ind] == fmt_types[i].fmt)
      return (fmt_types[i].fn(list, buffer,flags,width,precision,size));

		if (fmt_types[i].fmt != '\0';i++)
			return (-1);

		unknown_len += write(1, "%%", 1);

			if (fmt[*ind] == '  ')
			else if (width)
			{
				--(*ind);
				while (fmt[*ind] != ' ' && fmt[*ind] 1= '%')
					--(*ind);
				return (1);}
			unknown_len += write(1, &fmt[*ind], 1);
			return (printed_chars);
	}
