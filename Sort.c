/*
 * Contains the functions that will sort the linked lists
 * All sorting will be done using bubble sort
 */

#include "Sort.h"
#include "LInkedLists.h"
#include "typedef.h"
#include "Property.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

property_t *getPropertyAtIndex(node_t *pHead, int index) {
    node_t *pTemp = getNodeAtIndex(pHead, index);

    return &pTemp->property;
}

void setPropertyAtIndex(node_t *pHead, property_t *newProperty, int index) {
    node_t *pCurrent = pHead;

    for (int i = 0; i < index; i++) {
        if (pCurrent->next == NULL) { //if the index is wrong and we get the linked list equivalent of an IndexOutOfBounds Exception
            fprintf(stderr, "Set Property at Index, Index of %d is out of bounds\n, property has been set at final index", index); //hopefully this generates record in stderr
            break; //exit loop
        }
        pCurrent = pCurrent->next;
    }
    pCurrent->property = *newProperty;
}

void swapNodeValues(node_t *pHead, int indexA, int indexB) {
    property_t *propA = getPropertyAtIndex(pHead, indexA);
    property_t *propB = getPropertyAtIndex(pHead, indexB);

    setPropertyAtIndex(pHead, propA, indexB);
    setPropertyAtIndex(pHead, propB, indexA);
}

//performs the desired sort based on the input
void sortSwitcher(node_t *pHead, int sortMethod) {
    if (sortMethod == 0) {
        sortByAddress(pHead);
    }
    else if (sortMethod == 1) {
        sortByBedroom(pHead);
    }
    else if (sortMethod == 2) {
        sortByRent(pHead);
    }
    else if (sortMethod == 3) {
        sortByDistance(pHead);
    }
}

/*
 * for strcmp a == b = 0
 *a > b =+
 * a < b =-
 */
void sortByAddress(node_t *pHead) {
    int count = getCount(pHead);

    //sort by name
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (strcmp(prop1->pStreet->name, prop2->pStreet->name) > 0) { //if a > b
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //sort by number
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (strcmp(prop1->pStreet->name, prop2->pStreet->name) == 0 && prop1->houseNumber > prop2->houseNumber) { //strings are equal and a > b
                swapNodeValues(pHead, j, j+1);
            }
        }
    }
}

void sortByDistance(node_t *pHead) {
    int count = getCount(pHead);

    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (calculateDistance(prop1) > calculateDistance(prop2)) { //if a > b
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //secondary sort by street name
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (calculateDistance(prop1) == calculateDistance(prop2) && strcmp(prop1->pStreet->name, prop2->pStreet->name) > 0) { //if number of bedrooms are equal and nameA > nameB
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //tertiary sort by house number
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (calculateDistance(prop1) == calculateDistance(prop2) && strcmp(prop1->pStreet->name, prop2->pStreet->name) == 0 && prop1->houseNumber > prop2->houseNumber) { //if number of bedrooms and names are equal and numberA > number B
                swapNodeValues(pHead, j, j+1);
            }
        }
    }
}

void sortByBedroom(node_t *pHead) {
    int count = getCount(pHead);

    //primary sort by bedroom number
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->numberOfBedrooms > prop2->numberOfBedrooms) { //if a > b
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //secondary sort by street name
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->numberOfBedrooms == prop2->numberOfBedrooms && strcmp(prop1->pStreet->name, prop2->pStreet->name) > 0) { //if number of bedrooms are equal and nameA > nameB
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //tertiary sort by house number
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->numberOfBedrooms == prop2->numberOfBedrooms && strcmp(prop1->pStreet->name, prop2->pStreet->name) == 0 && prop1->houseNumber > prop2->houseNumber) { //if number of bedrooms and names are equal and numberA > number B
                swapNodeValues(pHead, j, j+1);
            }
        }
    }
}

void sortByRent(node_t *pHead) {
    int count = getCount(pHead);

    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->rentPerBedroom > prop2->rentPerBedroom) { //if a > b
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //secondary sort by street name
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->rentPerBedroom == prop2->rentPerBedroom && strcmp(prop1->pStreet->name, prop2->pStreet->name) > 0) { //if number of bedrooms are equal and nameA > nameB
                swapNodeValues(pHead, j, j+1);
            }
        }
    }

    //tertiary sort by house number
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            property_t *prop1 = getPropertyAtIndex(pHead, j);
            property_t *prop2 = getPropertyAtIndex(pHead, j+1);
            if (prop1->rentPerBedroom == prop2->rentPerBedroom && strcmp(prop1->pStreet->name, prop2->pStreet->name) == 0 && prop1->houseNumber > prop2->houseNumber) { //if number of bedrooms and names are equal and numberA > number B
                swapNodeValues(pHead, j, j+1);
            }
        }
    }
}

