/*
 * Where the action happens
 * Will contain the menu contained within a loop
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "Property.h"



//make a function that accepts a pointer to an array of streets and sets a randomly generated base distance for each one
//distance between 500-4000m
//generate random number within a range using (rand() % (max_number + 1 - minimum_number)) + minimum_number
//for some reason that I can't figure out this function has to be defined here for this to work
void setRandomStreetDistances () {
    for (int i = 0; i < 10; i++) {
        streets[i].distance = 100*((rand() % (41 - 5) ) +5);
    }
}

int main() {
    //initialize stuff here
    srand(time(0));
    setRandomStreetDistances();

    printStreets(streets);

    printProperty(createRandomProperty());
}


