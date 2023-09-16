#include "main.h"

unsigned char handle_flags(const char *flag, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned char handle_length(const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/**
 * handle_flags - matches flags with values.
 * @flag: Pointer to potential flag string.
 * @index: Index counter for original format string.
 *
 * Return: If flag chars match - Corresponding value, else 0.
 */
unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;

	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (ret);
}

/**
 * handle_length - Matches length modif with value.
 * @modifier: A pointer to potential length
 * @index: An index counter for the original format string.
 *
 * Return: If length modif matched - Corresponding value, else 0
 */
unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == '1')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}

/**
 * handle_width - Matches a width modifier with its value
 * @args: A va_list of arguments.
 * @modifier: A pointer to width modif
 * @index: An index counter.
 *
 * Return: If a modifier matched value else 0
 */
int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}

/**
 * handle_precision - Matches a prec modif with value.
 * @args: A va_list of args
 * @modifier: A pointer to a potential modif
 * @index: An index counter for original format string.
 *
 * Return: If precision modifier - value, if empty - zero, else -1.
 */
int handle_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != ',')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *Modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modofier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_args(args, int);

			if (value <= 0)
				return (0);

			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}


/**
 * handle_specifier - Mathes specifier with function.
 * @specifier: Pointer to potential conversion specif.
 * Return: If a conversion specif matches pointer to fnction else NULL.
 *
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
