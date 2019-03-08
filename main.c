/*
 * Where the action happens
 * Will contain the menu contained within a loop
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "Property.h"
#include "LInkedLists.h"

//Tests LinkedLists.c
void testLinkedList(street_t *pStreets, node_t *pUndecided) {
    //display the undecided list and the array of streets for reference
    printStreets(pStreets);
    printList(pUndecided);

    //remove sixth entry
    printf ("\nWas the 6th entry removed?\n");
    removeNodeAtIndex(&pUndecided, 5);
    printList(pUndecided);

    //remove first entry
    printf ("\nWas the 1st entry removed?\n");
    removeNodeAtIndex(&pUndecided, 0);
    printList(pUndecided);

    //remove at an invalid index
    printf ("\nWas a message generated in stderr?\n");
    removeNodeAtIndex(&pUndecided, 5);
    printList(pUndecided);

    //insert at index 1
    printf ("\nWas a new node inserted at index 1?\n");
    insertNodeAtIndex(&pUndecided, createNode(createRandomProperty(pStreets)), 1);
    printList(pUndecided);

    //insert at index 0
    printf ("\nWas a new node inserted at index 0?\n");
    insertNodeAtIndex(&pUndecided, createNode(createRandomProperty(pStreets)), 0);
    printList(pUndecided);

    //insert at invalid index
    printf ("\nWas a message generated in stderr and a new node appended to the end?\n");
    insertNodeAtIndex(&pUndecided, createNode(createRandomProperty(pStreets)), 10);
    printList(pUndecided);

    //test the count function
    printf ("\nThere should be 7 items in the list\n", getCount(pUndecided));
    printf ("There are currently %d items in the list\n", getCount(pUndecided));
    printList(pUndecided);
    //add an item
    insertNodeAtIndex(&pUndecided, createNode(createRandomProperty(pStreets)), 0);
    printf ("\nThere should be 8 items in the list\n", getCount(pUndecided));
    printf ("There are currently %d items in the list\n", getCount(pUndecided));
    printList(pUndecided);
    //remove two items
    removeNodeAtIndex(&pUndecided, 0);
    removeNodeAtIndex(&pUndecided, 0);
    printf ("\nThere should be 6 items in the list\n", getCount(pUndecided));
    printf ("There are currently %d items in the list\n", getCount(pUndecided));
    printList(pUndecided);

    //get node at index 4
    printf ("\nThere should now be a copy of the 5th item appended to the list\n");
    appendNode(&pUndecided, getNodeAtIndex(pUndecided, 4));
    printList(pUndecided);

    //get node at index 0
    printf ("\nThere should now be a copy of the 1st item appended to the list\n");
    appendNode(&pUndecided, getNodeAtIndex(pUndecided, 0));
    printList(pUndecided);
}

int main() {
    //initialize stuff here
    srand(time(0)); //seed rand
    street_t * pStreets = createArrayOfStreets(); //creates a pointer to the first element of our array of streets
    setRandomStreetDistances(pStreets);//assigns a random distance to each street
    node_t *pUndecided = createUndecidedList(pStreets); //creates undecided list with 6 random properties
    //end initialize

    testLinkedList(pStreets, pUndecided);
}


