/*
 * Will contain the node struct and all associated functions for handling the linked list
 */

#include "LInkedLists.h"
#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>

//count the number of items in a list
int getCount( node_t * pHead);

//find the i-th element in a list
node_t *getNodeAtIndex ( node_t *pHead, int index );


//append an item to the end of a list
void appendNode (node_t **ppHead, node_t *pNewNode);

//insert an item into a list at position
void insertNode ( node_t **ppHead, node_t *pNewNode, int index);

/*
 * Function that removes the first item of a list and returns a pointer to that item
 * We will do the following:
 * -Take the next item that the head points to and save it
 * -free the head item
 * -set the head to be the next item that we've stored on the side
 */
node_t *removeFirst(node_t ** ppHead) {
    node_t *returnValue;
    node_t * pNextNode = NULL;

    if (*ppHead == NULL) { //node is null
        return 0;
    }

    pNextNode = (*ppHead)->next; //nextnode now points to the same node as the head
    returnValue = *ppHead;
    free(*ppHead); // free the head item
    *ppHead = pNextNode;

    return returnValue;
}


/*remove the i-th item from a list and return a pointer to the item
* The process is:
* 1. Iterate to the node before the node we wish to delete
* 2. Save the node we wish to delete in a temporary pointer
* 3. set the previous node's next pointer to point to the node after the node we wish to delete
* 4. Delete the node using the temporary pointer
* Question: why not just free the item and return a copy of it instead of a pointer?
*/
node_t *removeNodeAtIndex ( node_t **ppHead, int index) {
    node_t *returnValue;

    node_t *pCurrent = *ppHead; //keeps track of current position
    node_t * pTemp = NULL;

    //removes first value
    if (index == 0) {
        return removeFirst(ppHead); //remove and return first item
    }

    //sets pCurrent to point to the node at index-1
    for (int i = 0; i < (index - 1); i++) {
        if (pCurrent->next == NULL) { //if the index is wrong and we get the linked list equivalent of an IndexOutOfBounds Exception
            return 0;
        }
        pCurrent = pCurrent->next;
    }

    pTemp = pCurrent->next; //makes temp point to the node we want to delete
    returnValue = pTemp; //we'll return a pointer to the deleted item
    pCurrent->next = pTemp->next; //pCurrent now points at what the node we're deleting was pointing to

    return pTemp; //return a pointer to the item we deleted
}



