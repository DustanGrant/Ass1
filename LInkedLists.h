//
// Created by Dustan on 2019-02-27.
//

#include "typedef.h"

#ifndef ASS1_LINKEDLISTS_H
#define ASS1_LINKEDLISTS_H

typedef struct node {
    property_t property;
    struct node * next;
}node_t;

extern int getCount( node_t * pHead);
extern node_t *getNodeAtIndex ( node_t *pHead, int index );
extern node_t *createUndecidedList(street_t *pStreets);
extern node_t *createNode(property_t *newProperty);
extern void printList(node_t * pHead);
extern void appendNode (node_t **ppHead, node_t *pNewNode);
extern void insertNodeAtIndex(node_t **ppHead, node_t *pNewNode, int index);
extern node_t *removeFirst(node_t ** ppHead);
extern node_t *removeNodeAtIndex ( node_t **ppHead, int index);

#endif //ASS1_LINKEDLISTS_H
