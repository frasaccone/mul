#ifndef _PARSE_H
#define _PARSE_H

#include <stddef.h>

#include "structure.h"

/* It updates the document node after parsing the given buf buffer of length
   buflen. The length of the buffer must not consider the NULL character of the
   buffer. */
void parsebuffer(struct node *document, char *buf, size_t buflen);

#endif
