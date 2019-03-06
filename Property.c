/*
 * Contains functions to initialize and handle property and street types
 * To do:
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "Property.h"
#include "typedef.h"


/*
 * returns a pointer to the first element of an array of ten streets
 */
street_t * createArrayOfStreets() {
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

    return &streets[0];
}

/*
 * Generates a random distance between 500-4000 for an array of 10 streets
 * accepts a pointer to the first member of that array
 */
void setRandomStreetDistances (street_t * streets) {
    for (int i = 0; i < 10; i++) {
        (streets+i)->distance = 100*((rand() % (41 - 5) ) +5);
    }
}


/*
 * Function that generates a random property and returns it
 */
property_t createRandomProperty(street_t * streets) {
    property_t new;
    int randomStreet = rand() % (10);
    int randomHouseNumber = (rand() % (200)) + 1; //1-200
    int randomBedroomNumber = (rand() % (4)) + 1; //1-4
    int randomRent = 50*((rand() % (12 + 1 - 4) ) + 4); //200-600

    new.pStreet = (streets+randomStreet); //pointer arithmetic in effect
    new.houseNumber = randomHouseNumber;
    new.numberOfBedrooms = randomBedroomNumber;
    new.rentPerBedroom = randomRent;

    return new;
}

/*
 * calculates the distance to a property
 */
float calculateDistance(property_t property) {
    float distance;

    distance = (property.pStreet->distance + (20 * property.houseNumber));
    distance = distance/1000; //convert to km

    return distance;
}

/*
 * Accepts an property and prints it in a nicely formatted way
 */
void printProperty(property_t printThis) {
    printf("%d %s, Number of Bedrooms: %d, Rent: $%d, Distance from campus %.2fkm",
            printThis.houseNumber,
            printThis.pStreet->name,
            printThis.numberOfBedrooms,
            printThis.rentPerBedroom,
            calculateDistance(printThis));
}

//function that accepts a pointer to an array of streets to print them
void printStreets ( street_t * streets) {
    for (int i = 0; i < 10; i++ ) {
        printf("Name: %s, Distance: %d\n", (streets+i)->name, (streets+i)->distance);
    }
}