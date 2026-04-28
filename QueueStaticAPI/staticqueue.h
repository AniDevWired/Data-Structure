#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stddef.h>

/* Queue */
typedef struct QueueStatic {
    ptrdiff_t front, rear;
    size_t len;
    int *data;
}QueueStatic;

/* Initialize the queue */
int queue_static_init(QueueStatic *q, size_t l);

/* Check if the queue is full or not */
int queue_static_isFull(const QueueStatic *q);

/* Check if the queue is empty or not */
int queue_static_isEmpty(const QueueStatic *q);

/* Insert element from rear */
int queue_static_insert(QueueStatic *q, const int value);

/* Remove element from front */
int queue_static_delete(QueueStatic *q);

/* List all the elements present in the queue */
int queue_static_traverse(QueueStatic *q);

/* Free the queue */
void queue_static_free(QueueStatic *q);

#endif