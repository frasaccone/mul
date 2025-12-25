#ifndef _STRUCTURE_H
#define _STRUCTURE_H

enum nodetype {
	NODE_DOCUMENT,

	NODE_ORDERED_LIST_ITEM,
	NODE_BLOCK_QUOTE,
	NODE_UNORDERED_LIST_ITEM,

	NODE_CODE_BLOCK,
	NODE_HEADER_1,
	NODE_HEADER_2,
	NODE_PARAGRAPH,
	NODE_THEMATIC_BREAK,
};

struct node {
	enum nodetype type;

	/* It is 0 if the node is open, or any non-0 integer if it is
	   closed. */
	unsigned int closed;

	/* The text content of the node. */
	char *content;

	/* The pointer to the next sibling. */
	struct node *sibling;

	/* The pointer to the first child. */
	struct node *children;
};

#endif
