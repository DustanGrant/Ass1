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
 * Function that generates a random property and returns it
 */
property_t createRandomProperty() {
    property_t new;
    int randomStreet = rand() % (10);
    int randomHouseNumber = rand() % (200 + 1);
    int randomBedroomNumber = (rand() % (4)) + 1;
    int randomRent = 50*((rand() % (12 + 1 - 4) ) + 4);

    new.pStreet = &streets[randomStreet];
    new.houseNumber = randomHouseNumber;
    new.numberOfBedrooms = randomBedroomNumber;
    new.rentPerBedroom = randomRent;

    return new;
}

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
void printStreets ( street_t streets[]) {
    for (int i = 0; i < 10; i++ ) {
        printf("Name: %s, Distance: %d\n", streets[i].name, streets[i].distance);
    }
}