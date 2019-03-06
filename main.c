/*
 * Where the action happens
 * Will contain the menu contained within a loop
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "Property.h"




int main() {
    //initialize stuff here
    srand(time(0));
    street_t * pStreets = createArrayOfStreets(); //creates a pointer to the first element of our array of streets
    setRandomStreetDistances(pStreets);//assigns a random distance to each street


    printStreets(pStreets);

    printProperty(createRandomProperty(pStreets));
}


