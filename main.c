/*
 * Where the action happens
 * Will contain the menu contained within a loop
 */

#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>

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



int main() {
    printf("%s", streets[0].name);
}


