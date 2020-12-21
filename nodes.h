#ifndef NODES
#define NODES

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *p_previous;
    struct Node *p_next;
};

void createList(struct Node **pp_root);
void insertAtEnd(struct Node **pp_root, int val);
void insertAtStart(struct Node **pp_root, int val);

void printListForwards(struct Node *p_root);
void printListBackwards(struct Node *p_root);

void deleteLargest(struct Node **pp_root);

void destroyList(struct Node **pp_root);


#endif