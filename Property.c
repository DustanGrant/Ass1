/*
 * Contains functions to initialize and handle property and street types
 */
#include <stdio.h>
#include <stdlib.h>
#include "Property.h"
#include "typedef.h"





//function that accepts a pointer to an array of streets to print them
void printStreets ( street_t streets[]) {
    for (int i = 0; i < 10; i++ ) {
        printf("Name: %s, Distance: %d\n", streets[i].name, streets[i].distance);
    }
}