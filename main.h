#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag modifier macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* length modif macros */
#define SHORT 1
#define LONG 2

int _printf(const char *format, ...);

/**
 * struct buffer_s - A new type defining buffer.
 * @buffer: Pointer to a character array.
 * @start: Pointer to start of buffer.
 * @len: Length of string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - A new type defining converters.
 * @specifier: A character representing a conversion specif
 * @func: A pointer to conversion function.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type def a flag struct
 * @flag: A character rep a flag
 * @value: Integer value of the flag
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned char handle_length(const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifiers))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/* modifiers */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output, unsigned char flags,
		int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

/* Helpers */
buffer_t *init_buffer(void);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);

#endif
