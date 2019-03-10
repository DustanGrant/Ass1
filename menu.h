/*
 * contains functions to accept user input as well as a function that will serve as the menu
 */

#include "typedef.h"
#include "LInkedLists.h"

#ifndef ASS1_MENU_H
#define ASS1_MENU_H

enum stateEnum {
    Unsupported = 0,
    Input = 1,
    Help = 2,
    Quit = 3,
    All = 4,
    Undecided = 5,
    Favourites = 6,
    Sort = 7,
    SortByRent = 8,
    SortByDistance = 9,
    SortByRooms = 10,
    SortByAddress = 11,
    Next = 12,
    Left = 13,
    Right = 14
};

extern int getInput();
extern void menu(street_t *pStreets, node_t *pUndecided, node_t *pFavourites);

#endif //ASS1_MENU_H
