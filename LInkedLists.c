/*
 * Will contain the node struct and all associated functions for handling the linked list
 */

#include "LInkedLists.h"
#include "typedef.h"
#include <stdio.h>

//count the number of items in a list
int getCount( node_t * pHead);

//find the i-th element in a list
node_t *getNodeAtIndex ( node_t *pHead, int i );


//append an item to the end of a list
void appendNode (node_t **ppHead, node_t *pNewNode);

//insert an item into a list at position
void insertNode ( node_t **ppHead, node_t *pNewNode, int i);

//remove the i-th item from a list and return a pointer to the item
//why not just free the item and return a copy of it?
node_t *removeNodeAtIndex ( node_t **ppHead, int i);



