#ifndef LL_INT_H
#define LL_INT_H

#include <stddef.h>

/* Linked List Node */
typedef struct Node {
    /* store an integer value */
    int data;
    /* link to next node */
    Node *link;
} Node;

/* Append a value to Linked List */
void append_ll_int();

/* Append a value at begining of the Linked List */
void addatbegin_ll_int();

/* Append a value at the end of Linked List */
void addatafter_ll_int();

/* Display length of the Linked List */
void length_ll_int();

/* Display elements of the Linked List */
void display_ll_int();

/* Delete a node in the Linked List */
void delete_ll_int();