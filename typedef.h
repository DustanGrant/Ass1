/*
 * defines the street and rental property structs
 */

#ifndef ASS1_TYPEDEF_H
#define ASS1_TYPEDEF_H

typedef struct street {
    char * name;
    int distance;
}street_t;

typedef struct RentalProperty {
    street_t *pStreet;
    int houseNumber;
    int rentPerBedroom;
    int numberOfBedrooms;
}property_t;


#endif //ASS1_TYPEDEF_H
