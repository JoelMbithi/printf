#include "main.h"

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
buffer_t *init_buffer(void);

/**
 * _memcpy - Copies n bytes from memory area src to buffer in buffer_t.
 * @output: A buffer_t struct.
 * @src: Pointer to memoery area to copy
 * @n: Number of bytes to copy.
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;

	}

	return (n);
}


/**
 * init_buffer - Initialises buffer_t variable
 *
 * Return: A pointer to initialised buffer
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));

	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);

	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
