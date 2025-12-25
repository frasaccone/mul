#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

/* It returns the last open child of node b. If b has no open children, NULL
   is returned instead. */
static struct node *lastopenchild(struct node *n);

struct node *
lastopenchild(struct node *n)
{
	struct node *c, *lastopen = NULL;

	for (c = n->children; c && c->sibling; c = c->sibling) {
		if (!c->closed)
			lastopen = c;
	}

	return lastopen;
}

void
parseline(struct node *document, char *line)
{
	struct node *c, *lastopen;

	/* Make lastopen the deepest last open child of document, or make it
	   document if it has no open children. */
	lastopen = document;
	while ((c = lastopenchild(lastopen)))
		lastopen = c;

	lastopen->content = addtobuffer(lastopen->content,
	                                lastopen->content
	                                ? strlen(lastopen->content)
	                                : 0,
	                                line,
	                                strlen(line));
}
