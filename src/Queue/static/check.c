#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "staticqueue.h"

int main(void) {

    QueueStatic queue = {0};

    long long tmp;
    printf("Enter len of queue: ");
    if(scanf("%lld",&tmp) != 1 || tmp < 0) {
        fprintf(stderr, "Invalid input!");
        return -1;
    }

    if(queue_static_init(&queue, (size_t)tmp) != 0) {
        fprintf(stderr, "queue initialization failed");
        return -1;
    }

    int c = 0;

    do {
        printf("Enter 1: Insert || 2: Delete || 3: Traverse\t0: Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&c) != 1) {
            fprintf(stderr,"Bad input!");
            queue_static_free(&queue);
            return -1;
        }
        
        switch (c)
        {
        case 1:
            printf("\nEnter a value to insert: ");
            int val;
            if(scanf("%d",&val) != 1) {
                fprintf(stderr,"Bad input!");
                queue_static_free(&queue);
                return -1;
            }
            if(queue_static_insert(&queue, val) != 0) {
                printf("\nThe queue is full!\n");
            }
            break;

        case 2:
            int val_hehe = queue_static_delete(&queue);
            if(val_hehe == -1) {
                printf("\nThe queue is empty!\n");
            } else {
                printf("\nPopped value: %d\n",val_hehe);
            }
            break;

        case 3: 
            printf("\nCurrent queue is: \n");
            queue_static_traverse(&queue);
            break;

        case 0:
            queue_static_free(&queue);
            return 0;
        
        default:
            printf("\nInvalid Choice!\n");
            break;
        }
    } while (1);
}