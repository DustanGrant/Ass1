/*
 * 
 */
#include "typedef.h"

#ifndef ASS1_PROPERTY_H
#define ASS1_PROPERTY_H

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

extern property_t createRandomProperty();
extern void printProperty(property_t printThis);
extern void printStreets( street_t streets[] ) ;
#endif //ASS1_PROPERTY_H
