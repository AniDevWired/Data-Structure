#ifndef LL_INT_H
#define LL_INT_H

#include <stddef.h>

/* Linked List Node */
typedef struct Node {
    /* store an integer value */
    int data;
    /* link to next node */
    struct Node *link;
} Node;

/* Append a value to Linked List */
void append_ll_int(const int data);

/* Append a value at begining of the Linked List */
void addatbegin_ll_int(const int data);

/* Append a value at the given location of Linked List */
void addatloc_ll_int(const int data, const int loc);

/* Append a value at the middle of Linked List */
void addatlmid_ll_int(const int data);

/* Display length of the Linked List */
int length_ll_int();

/* Display elements of the Linked List */
void display_ll_int();

/* Delete a node in the Linked List */
void delete_ll_int(const int loc);

#endif