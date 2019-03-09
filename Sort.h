//
// Created by Dustan on 2019-02-28.
//
#include "typedef.h"
#include "LInkedLists.h"

#ifndef ASS1_SORT_H
#define ASS1_SORT_H

extern property_t getPropertyAtIndex(node_t *pHead, int index);
extern void setPropertyAtIndex(node_t *pHead, property_t newProperty, int index);
extern void swapNodeValues(node_t *pHead, int indexA, int indexB);
extern void sortByAddress(node_t *pHead);
extern void sortByDistance(node_t *pHead);
extern void sortByBedroom(node_t *pHead);
extern void sortByRent(node_t *pHead);

#endif //ASS1_SORT_H
