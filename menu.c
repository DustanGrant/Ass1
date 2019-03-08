//
// Created by Dustan on 2019-03-04.
//

#include "menu.h"

int menu(){

	char *input;
	input = calloc(2, sizeof(char));
	printf("Command ('h' for help): ");
	scanf("%s", input);

	//switch statement with all functions

}

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