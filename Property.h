/*
 * 
 */
#include "typedef.h"

#ifndef ASS1_PROPERTY_H
#define ASS1_PROPERTY_H

extern street_t * createArrayOfStreets();
extern void setRandomStreetDistances (street_t * streets);
extern property_t createRandomProperty(street_t * streets);
extern void printProperty(property_t printThis);
extern void printStreets( street_t * streets ) ;
#endif //ASS1_PROPERTY_H
