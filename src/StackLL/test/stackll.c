#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* prototypes */
void push(void);
void pop(void);
void peek(void);
void traverse(void);

/* Node */
typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

int main(void) {

    int c = 0;

    do {
        printf("Enter 1: Push || 2: Pop || 3: Peek || 4: Traverse\t0: Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&c) != 1) {
            return -1;
        }

        switch (c) {
            case 1: push();
                break;
            
            case 2: pop();
                break;
            
            case 3: peek();
                break;
            
            case 4: traverse();
                break;

            case 0: exit(0);
                break;
            
            default: printf("\nInvalid Choice!\n");
        }
    } while (1);
}

void push() {
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf(" %d", &temp->data);

    temp->link = top;
    top = temp; 
}

void pop() {
    Node *temp;
    
    if(top == NULL) {
        printf("\nNo elements to delete\n");
        return;
    }

    temp = top;
    printf("Popped element is: %d\n", temp->data);
    top = temp->link;
    temp->link = NULL;
    free(temp);
}

void peek() {
    Node *temp;
    
    if(top == NULL) {
        printf("\nNo elements to delete\n");
        return;
    }

    temp = top;
    printf("Peeked element is: %d", temp->data);
}

void traverse() {
    Node *temp;
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("The stack is: \n");
    while (temp != NULL) {
        printf("\t%d\n",temp->data);
        temp = temp->link;
    }
}
