#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* Node */
struct Node {
    // data of the node
    int data;
    // link to another node
    struct Node *next;
};

int main(void) {
    struct Node *n = malloc(sizeof(struct Node));
    if(!n) return -1;
    printf("sizeof(Node *n): %ld\n", sizeof(struct Node));
    printf("malloc_usable_size: %ld\n", malloc_usable_size(n));

    free(n);
    return 0;
}
