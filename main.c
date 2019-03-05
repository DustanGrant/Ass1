/*
 * Where the action happens
 * Will contain the menu contained within a loop
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "Property.h"

//make a global static array of 10 streets
static street_t streets[] = {
        {.name ="Koala Bear Avenue", .distance=0},
        {.name ="Platypus Drive", .distance=0},
        {.name ="Wallaby Way", .distance=0},
        {.name ="Kangaroo Street", .distance=0},
        {.name ="Dingo Promenade", .distance=0},
        {.name ="Emu Street", .distance=0},
        {.name ="Cassowary Road", .distance=0},
        {.name ="Drop Bear Court", .distance=0},
        {.name ="Echidna Avenue", .distance=0},
        {.name ="Box Jellyfish Boulevard", .distance=0}
};

//make a function that accepts a pointer to an array of streets and sets a randomly generated base distance for each one
//distance between 500-4000m
//generate random number within a range using rand() % (max_number + 1 - minimum_number) + minimum_number
void setRandomStreetDistances () {
    for (int i = 0; i < 10; i++) {
        streets[i].distance = 100*(random() % (40 - 5) +5);
    }
}

int main() {
    srand(time(0));

    setRandomStreetDistances();
    printStreets(streets);
}


