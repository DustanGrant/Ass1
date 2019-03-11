/*
 * Contains everything that the user will see
 * contains the menu which can be implemented as a single function in main
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "typedef.h"
#include "Property.h"
#include "LInkedLists.h"
#include "Sort.h"
#include "menu.h"

//strcmp that doesn't care about case
int caseInsensitiveStrcmp(char const *a, char const *b) {
    while(1) {
        int returnValue = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (returnValue != 0 || !*a) {
            return returnValue;
        }
        a++;
        b++;
    }
}

/*
 * Accepts user input and returns an int corresponding to the enum in the header file
 */
int getInput() {
	char input[8];
	int output = 0;
	printf("\nCommand: ('h' for help)\n\t");
	scanf("%s", input);

	if (caseInsensitiveStrcmp(input, "h") == 0) {
		output = Help;
	}
	else if (caseInsensitiveStrcmp(input, "q") == 0) {
		output = Quit;
	}
	else if (caseInsensitiveStrcmp(input, "a") == 0) {
		output = All;
	}
	else if (caseInsensitiveStrcmp(input, "u") == 0) {
		output = Undecided;
	}
	else if (caseInsensitiveStrcmp(input, "f") == 0) {
		output = Favourites;
	}
	else if (caseInsensitiveStrcmp(input, "s") == 0) {
		output = Sort;
	}
	else if (caseInsensitiveStrcmp(input, "sr") == 0) {
		output = SortByRent;
	}
	else if (caseInsensitiveStrcmp(input, "sd") == 0) {
		output = SortByDistance;
	}
	else if (caseInsensitiveStrcmp(input, "sn") == 0) {
		output = SortByRooms;
	}
	else if (caseInsensitiveStrcmp(input, "sa") == 0) {
		output = SortByAddress;
	}
	else if (caseInsensitiveStrcmp(input, "n") == 0) {
		output = Next;
	}
	else if (caseInsensitiveStrcmp(input, "l") == 0) {
		output = Left;
	}
	else if (caseInsensitiveStrcmp(input, "r") == 0) {
		output = Right;
	}
	else {
		output = Unsupported;
	}

	return output;
}

/*
 * All menu actions should be performed in this function
 */
void menu(street_t *pStreets, node_t *pUndecided, node_t *pFavourites) {
	//flags go here
	int state = All; //state flag that uses the enum labels
	int exitTheLoop = 0;
	int listState = -1; //-1 for undecided, 1 for favourites
	int sortMethod = 0;
	int currentIndex = 0;

	while(exitTheLoop == 0){
		switch (state) {
			case Input: {
				state = getInput();
				break;
			}
			case Help: {
				printf("\nValid commands are:\n");
				printf("\th - display this help\n");
				printf("\ta - display all the rental properties on the current list\n");
				printf("\tf - switch to the favourites list\n");
				printf("\tu - switch to the undecided list\n");
				printf("\tl - 'swipe left' on the current rental property\n");
				printf("\tr - 'swipe right' on the current rental property\n");
				printf("\tsa - set the sorting to 'by address(ascending)'\n");
				printf("\tsn - set the sorting to 'by number of rooms(ascending)'\n");
				printf("\tsd - set the sorting to 'by distance(ascending)'\n");
				printf("\tsr - set the sorting to 'by rent(ascending)'\n");
				printf("\tq - quit the program\n");

				state = Input;
				break;
			}
			case All: {
				if (listState == -1) { //undecided
					if (pUndecided != NULL) { //list is not NULL
						printf("\nUndecided List: \n"); //list title
						sortSwitcher(pUndecided, sortMethod); //sort
						printList(pUndecided); //display list
						viewProperty(getPropertyAtIndex(pUndecided, currentIndex)); //display property at current index
						state = Input;//return to input
					} else {
						printList(pUndecided); //display empty message
						printf("\nSwitching to Favourites List\n");
						state = Favourites; //switch to favourites
					}
				}
				if (listState == 1) { //favourites
					printf("\nFavourites List: \n");
					if (pFavourites != NULL) {
						sortSwitcher(pFavourites, sortMethod);
						printList(pFavourites);
						viewProperty(getPropertyAtIndex(pFavourites, currentIndex));
						state = Input;
					} else {
						printList(pFavourites);
						printf("\nSwitching to undecided list\n");
						state = Undecided; //switch to undecided
					}
				}
				break;
			}
			case Undecided: {
				if (listState == 1) {
					listState = -1; //switch list to undecided
					currentIndex = 0; //reset index

					if (rand() % 2 == 0) { //50% chance
						appendNode(&pUndecided, createNode(createRandomProperty(pStreets))); //create and append random property
						printf("\nA new property has been added to the undecided list\n");
					}
				}
				else {
					printf("\nYou're already viewing the undecided list\n");
				}


				state = All; //back to All
				break;
			}
			case Favourites: {
				if (listState == -1) {
					listState = 1; //switch list
					currentIndex = 0; //reset index
				}
				else {
					printf("\nYou're already viewing the favourites list\n");
				}

				state = All; //do an all
				break;
			}
			case Sort: {
				state = All;
				break;
			}
			case SortByAddress: {
				sortMethod = 0;
				state = All;
				currentIndex = 0; //return to start of list
				break;
			}
			case SortByRooms: {
				sortMethod = 1;
				state = All;
				currentIndex = 0; //return to start of list
				break;
			}
			case SortByRent: {
				sortMethod = 2;
				state = All;
				currentIndex = 0; //return to start of list
				break;
			}
			case SortByDistance: {
				sortMethod = 3;
				state = All;
				currentIndex = 0; //return to start of list
				break;
			}
			case Next: {
				if (listState == -1) { //undecided
					if (currentIndex < getCount(pUndecided) -1) {
						currentIndex++;
					}
					else {
						printf("\nYou have reached the end of the list, returning to start\n");
						currentIndex = 0;
					}
				}
				if (listState == 1) { //favourites
					if (currentIndex < getCount(pFavourites) -1) {
						currentIndex++;
					}
					else {
						printf("\nYou have reached the end of the list, returning to start\n");
						currentIndex = 0;
					}
				}
				state = All;
				break;
			}
			case Left: { //reject
				if (listState == -1) { //undecided
					node_t *freeThis = (removeNodeAtIndex(&pUndecided, currentIndex)); //temporary pointer points to removed node
					free(freeThis->property); //free the property therein
					free(freeThis); //free the node

					printf("\nItem removed from Undecided list\n");
                    if (currentIndex >= getCount(pUndecided)) { //if index goes out of bounds
                        currentIndex = getCount(pUndecided) - 1; //readjust index
                    }
				}
				if (listState == 1) { //favourites
					node_t *freeThis = (removeNodeAtIndex(&pFavourites, currentIndex)); //free up the memory
					free(freeThis->property); //free the property therein
					free(freeThis); //free the node

					printf("\nItem removed from Favourites list\n");
                    if (currentIndex >= getCount(pFavourites)) { //if index goes out of bounds
                        currentIndex = getCount(pFavourites) -1; //readjust index
                    }
				}

				state = All;
				break;
			}
			case Right: { //approve
				if (listState == -1) { //undecided
					appendNode(&pFavourites, removeNodeAtIndex(&pUndecided, currentIndex));
					printf("\nItem added to Favourites list\n");
                    if (currentIndex >= getCount(pUndecided)) { //if index goes out of bounds
                        currentIndex = getCount(pUndecided) - 1; //readjust index
                    }
				}
				if (listState == 1) { //favourites
					printf("\nItem is already in favourites list\n");
				}

				state = All;
				break;
			}
			case Quit: {
				printf("\nExiting program, have a nice day");
				exitTheLoop = 1;
				break;
			}
			case Unsupported: {
				printf("\nCommand unsupported, returning to help\n");
				state = Help;
				break;
			}
			default: {
				state = Unsupported;
				break;
			}
		}
	}


}