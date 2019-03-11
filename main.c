/* PROGRAM: Assignment 1
   AUTHOR: Dustan Grant (040911882) & Karanpreet Singh Mann (040912515)
   DATE: 2019-03-11
   PURPOSE: Make a rental property viewing application that simulates listings by generating properties randomly
   LEVEL OF DIFFICULTY: 4
   CHALLENGES: Correcting all instances of structs being passed by value
   HOURS SPENT: 20 hours
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "Property.h"
#include "LInkedLists.h"
#include "Sort.h"
#include "menu.h"

//unit tests fo Linked lists
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
    printf ("\nThere should be 7 items in the list\n");
    printf ("There are currently %d items in the list\n", getCount(pUndecided));
    printList(pUndecided);
    //add an item
    insertNodeAtIndex(&pUndecided, createNode(createRandomProperty(pStreets)), 0);
    printf ("\nThere should be 8 items in the list\n");
    printf ("There are currently %d items in the list\n", getCount(pUndecided));
    printList(pUndecided);
    //remove two items
    removeNodeAtIndex(&pUndecided, 0);
    removeNodeAtIndex(&pUndecided, 0);
    printf ("\nThere should be 6 items in the list\n");
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

//unit tests for node removal
void testNodeRemoval(street_t *pStreets, node_t *pUndecided) {
    //display the undecided list and the array of streets for reference
    printStreets(pStreets);
    printList(pUndecided);

    //remove five entries from list
    printf ("\nremove five entries from the list\n");
    for (int i = 0; i < 5; i++) {
        removeNodeAtIndex(&pUndecided, 0);
    }
    printList(pUndecided);

    printf ("\nRemove final entry from the list and print\n");
    removeNodeAtIndex(&pUndecided, 0);
    printList(pUndecided);
}

//unit tests for sort.c
void testSort(street_t *pStreets, node_t *pUndecided) {
    //append a bunch of new nodes to the undecided list
    for (int i = 0; i < 30; i++) {
        appendNode(&pUndecided, createNode(createRandomProperty(pStreets)));
    }


    printf ("\nStreets\n");
    printStreets(pStreets);

    printf ("\nInitial Undecided List\n");
    printList(pUndecided);

    printf ("\nTest 1: Retrieve and print the property contained in the node at index 0\n");
    printProperty(getPropertyAtIndex(pUndecided, 0));

    printf ("\n\nTest 2: Set a new property at index 0\n");
    setPropertyAtIndex(pUndecided, createRandomProperty(pStreets), 0);
    printList(pUndecided);

    printf("\nTest 3: Swap the values at index 1 and index 3\n");
    swapNodeValues(pUndecided, 1, 3);
    printList(pUndecided);

    printf("\nTest 4: Test sort by address\n");
    sortByAddress(pUndecided);
    printList(pUndecided);

    printf("\nTest 5: Test sort by distance\n");
    sortByDistance(pUndecided);
    printList(pUndecided);

    printf("\nTest 6: Test sort by bedroom\n");
    sortByBedroom(pUndecided);
    printList(pUndecided);

    printf("\nTest 7: Test sort by rent\n");
    sortByRent(pUndecided);
    printList(pUndecided);
}

int main() {
    //initialize stuff here
    srand((unsigned int)time(0)); //seed rand
    street_t * pStreets = createArrayOfStreets(); //creates a pointer to the first element of our array of streets
    setRandomStreetDistances(pStreets);//assigns a random distance to each street
    node_t *pUndecided = createUndecidedList(pStreets); //creates undecided list with 6 random properties
    node_t *pFavourites = NULL; //starts off as null but will later be set to the first item added to the favourites list, may need to be a double pointer, we'll find out
    //end initialize


    menu(pStreets, pUndecided, pFavourites);
}


