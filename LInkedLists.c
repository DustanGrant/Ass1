/*
 * Will contain the node struct and all associated functions for handling the linked list
 * To Do:
 *
 */

#include "LInkedLists.h"
#include "typedef.h"
#include "Property.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *creates a linked list with 6 random properties
 */
node_t *createUndecidedList(street_t *pStreets) {
    node_t *pHead;
    pHead = createNode(createRandomProperty(pStreets));

    for (int i = 0; i < 5; i++) {
        node_t *pNewNode;
        pNewNode = createNode(createRandomProperty(pStreets));
        appendNode(&pHead, pNewNode);
    }

    return pHead;
}

/*
 * Function that accepts a property as an argument and mallocs space for a node containing that property and pointing to NULL
 * before returning a pointer to that node
 */
node_t *createNode(property_t newProperty) {
    node_t *pHead = malloc(sizeof(node_t));

    pHead->property = newProperty;
    pHead->next = NULL;

    return pHead;
}

//count the number of items in a list
int getCount( node_t * pHead) {
    int count = 0;
    node_t *pCurrent = pHead;

    while (pCurrent != NULL) {
        count++;
        pCurrent = pCurrent->next;
    }

    return count;
}

//find the i-th element in a list
node_t *getNodeAtIndex ( node_t *pHead, int index ){
    node_t *pCurrent = pHead;
    node_t *pTemp = malloc(sizeof(node_t));
    pTemp->property = pCurrent->property;
    pTemp->next = NULL;


    for (int i = 0; i < index; i++) {
        if (pCurrent->next == NULL) { //if the index is wrong and we get the linked list equivalent of an IndexOutOfBounds Exception
            fprintf(stderr, "Get Node at Index, Index of %d is out of bounds\n", index); //hopefully this generates record in stderr
            pTemp->property = pCurrent->property;
            return pTemp;
        }
        pCurrent = pCurrent->next;
    }
    pTemp->property = pCurrent->property;
    return pTemp;
}

/*
 * Prints the contents of a list
 */
void printList(node_t * pHead) {
    node_t *pCurrent = pHead;

    while (pCurrent != NULL) {
        printProperty(pCurrent->property);
        printf("\n");
        pCurrent = pCurrent->next;
    }
}

//append an item to the end of a list
void appendNode (node_t **ppHead, node_t *pNewNode) {
    node_t *pCurrent = *ppHead; //keeps track of our position

    //sets pCurrent to point to last node in list
    while (pCurrent->next != NULL) {
        pCurrent = pCurrent->next;
    }

    pCurrent->next = pNewNode;
    pCurrent->next->next = NULL; //cuts off any nodes the new node was connected to
}

//insert an item into a list at position
/*
 * we will do the following:
 * -navigate to the specified index -1
 * -make the new node point to the same value as the current index
 * -make the current index point to the new node
 */
void insertNodeAtIndex(node_t **ppHead, node_t *pNewNode, int index) {
    node_t *pCurrent = *ppHead;

    if (index != 0) {
        //navigate to index
        for (int i = 0; i < index-1; i++) {
            if (pCurrent->next == NULL) { //if the index is wrong and we get the linked list equivalent of an IndexOutOfBounds Exception
                fprintf(stderr, "Insert Node at Index, Index of %d is out of bounds, Appended to end\n", index); //hopefully this generates record in stderr
                break; //stops us before we run out of list
            }
            pCurrent = pCurrent->next;
        }

        pNewNode->next = pCurrent->next;
        pCurrent->next = pNewNode;
    } else {
        pNewNode->next = pCurrent;
        *ppHead = pNewNode;
    }

}

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
 * Answer: After the node is returned we can either put it into a new list or free it outside the function
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
            fprintf(stderr, "Remove node at Index, Index of %d is out of bounds, nothing was removed\n", index); //hopefully this generates record in stderr
            return 0;
        }
        pCurrent = pCurrent->next;
    }

    pTemp = pCurrent->next; //makes temp point to the node we want to delete
    returnValue = pTemp; //we'll return a pointer to the deleted item
    pCurrent->next = pTemp->next; //pCurrent now points at what the node we're deleting was pointing to

    return pTemp; //return a pointer to the item we deleted
}



