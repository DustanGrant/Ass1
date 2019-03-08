/*
 * Recommended Structure for menu .c
 * Ideally I would want only two functions to be in the file
 * I'll include declarations with comments below
 * I'll be online more often than not so feel free to ask for help or clarification
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "typedef.h"
#include "Property.h"
#include "LInkedLists.h"
#include "Sort.h"

/*
 * -This function should accept user input and convert the character(s) to an associated integer value which will be passed to the switch statement in menu
 * -This means that every menu option will have a number associated with it allowing us to use a switch statement for the actual menu
 * 	I think this will good for readability over using a large set of if else statements in the menu
 * -if the user enters a value that doesn't match you should return an int that corresponds to the unsupported command option
 * -You may want to use an enum to define the menu values this would make the switch statement very readable ex. case swipeLeft:
 *  	If you decide to use an enum please create it in the header file
 */
int getInput() {
	//there should be a chain of if elses in here to assign an int value based on the input
	//according to the assignment outline you can go easy on the input validation
}

/*
 * All menu actions should be performed in this function
 */
void menu(street_t *pStreets, node_t *pUndecided, node_t *pFavourites) {
	//place the switch statement inside a while loop with a condition like while (exitTheLoop == 0) you can change the flag value when the user selects the quit option
	//look at strategy #11 in the assignment outline to see what I mean by "dummy branches" or stub functions

}

//repurpose this for the input function
int menu(){

	char *input;
	input = calloc(2, sizeof(char));
	printf("Command ('h' for help): ");
	scanf("%s", input);

	//switch statement with all functions

}

//get rid of everything below here and just perform the actions in the appropriate spot of the menu function
void help(){

	printf("Valid commands are:\n");
	printf("	h - display this help");
	printf("	a - display all the current properties on the current list");
	printf("	f - switch to the favourites list");
	printf("	u - switch to the undecided list");
	printf("	l - 'swipe left' on the current rental property");
	printf("	r - 'swipe right' on the current rental property");
	printf("	n - skip to the next rental property");
	printf("	sa - set the sorting to 'by address'");
	printf("	sn - set the sorting to 'by number of rooms'");
	printf("	sr - set the sorting to 'by rent'");
	printf("	sd - set the sorting to 'by distance'");
	printf("	q - quit the program");

	menu();

}

void displayProperties(){

}

void switchfavourites(){

}

void switchundecided(){

}

void leftswipe(){

}

void rightswipe(){

}

void nextproperty(){

}

void sortAddress(){

}

void sortRooms(){

}

void sortRent(){

}

void setDistance(){

}

void quit(){
	
}