#include "main.h"

unsigned int convert_ubase(buffer_t *output
		unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);


/**
 * convert_ubase - Converts an unsigned long to an inputted base and stores.
 * result to a buffer contained in a structure.
 *
 * @output
