#include "staticqueue.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CAPACITY 100

int queue_static_init(QueueStatic *q, size_t l) {
    if(l > SIZE_MAX/sizeof *q->data) return -1;

    if(l > MAX_CAPACITY) return -1;

    q->data = malloc(l * sizeof *q->data);
    if(!q->data) return -1;

    q->len = l;
    q->front = q->rear = 0;

    return 0;
}

int queue_static_isFull(const QueueStatic *q) {
    if(q->rear == (ptrdiff_t)q->len) return 1;
    return 0;
}

int queue_static_isEmpty(const QueueStatic *q) {
    if(q->front == q->rear) return 1;
    return 0;
}

int queue_static_insert(QueueStatic *q, const int value) {
    if(!q->data) return -1;
    if(queue_static_isFull(q)) return -1;
    
    q->data[q->rear] = value;
    q->rear++;

    return 0;
}

int queue_static_delete(QueueStatic *q) {
    if(!q->data) return -1;
    if(queue_static_isEmpty(q)) return -1;
    int val = q->data[q->front];
    for(ptrdiff_t i = 0; i+1 < q->rear; ++i) {
        q->data[i] = q->data[i+1];
    }
    q->rear--;
    return val;
}

int queue_static_traverse(QueueStatic *q) {
    if(!q->data) return -1;
    if(queue_static_isEmpty(q)) return -1;
    for(ptrdiff_t i = 0; i < q->rear; ++i) {
        printf("%d\n",q->data[(size_t)i]);
    }
    return 0;
}

void queue_static_free(QueueStatic *q) {
    if(!q) return;
    free(q->data);
    q->data = NULL;
    q->front = q->rear = 0;
    q->len = 0;
}
