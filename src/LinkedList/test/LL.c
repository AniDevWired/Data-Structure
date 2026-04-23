#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *root = NULL;

void LL_append(void);
void LL_addatbegin(void);
void LL_addatmid(void);
void LL_addatloc(void);
int LL_length(void);
void LL_display(void);
void LL_delete(void);

int main(void) {

    int ch;
    while(1) {
        printf("----Single Linked List----\n");
        printf("1. Append\n");
        printf("2. Add at begining\n");
        printf("3. Add at a specific location\n");
        printf("4. Add at middle\n");
        printf("5. Length\n");
        printf("6. Display\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                LL_append();
                break;

            case 2: 
                LL_addatbegin();
                break;

            case 3: 
                LL_addatloc();
                break;

            case 4: 
                LL_addatmid();
                break;

            case 5:  
                printf("\nThe length of the linked list is: %d\n\n", LL_length());
                break;

            case 6:  
                LL_display();
                break;

            case 7:  
                LL_delete();
                break;

            case 8: 
                exit(1);
                break;
            
            default: 
                printf("Invalid option!!!\n\n");
                break;
        }
    }

    return 0;
}

void LL_append() {
    Node *temp;
    temp = malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        Node *newNode;
        newNode = root;
        while(newNode->link != NULL) {
            newNode = newNode->link;
        }
        newNode->link = temp;
    }
}

void LL_addatbegin(void) {
    Node *temp;
    temp = malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    if(root == NULL) {
        root = temp;
    } else {
        temp->link = root;
        root = temp;
    }
}

void LL_addatmid(void) {
    Node *temp;
    temp = malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    int mid = LL_length()/2;

    if(root == NULL) {
        root = temp;
    } else {
        Node *newNode;
        newNode = root;
        while (mid > 1) {
            newNode = newNode->link;
            mid--;
        }
        temp->link = newNode->link;
        newNode->link = temp;
    }
}

void LL_addatloc(void) {
    int loc;
    printf("Enter location: ");
    scanf("%d", &loc);

    if(loc < 1 || loc > LL_length()) {
        printf("Invalid location!!\n\n");
        return;
    }

    if(loc == 1) {
        LL_addatbegin();
    } else if(loc == LL_length()) {
        LL_append();
    } else {
        Node *temp;
        temp = malloc(sizeof(Node));

        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        Node *newNode;
        newNode = root;
        while (loc > 1) {
            newNode = newNode->link;
            loc--;
        }
        temp->link = newNode->link;
        newNode->link = temp;
        
    }
}

int LL_length() {
    Node *temp;
    temp = root;
    if(temp == NULL) {
        return 0;
    }
    int c = 0;
    while(temp != NULL) {
        c++;
        temp = temp->link;
    }
    return c;
}

void LL_display() {
    Node *temp;
    temp = root;
    if(temp == NULL) {
        printf("\nList is empty!!\n\n");
        return;
    }
    while(temp != NULL) {
        printf("%d-->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n\n");
}

void LL_delete(void) {
    int loc;
    printf("Enter location: ");
    scanf("%d", &loc);

    if(loc < 1 || loc > LL_length()) {
        printf("Invalid location!!\n\n");
        return;
    }

    if(loc == 1) {
        Node *temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    } else {
        Node *p = root, *q;
        while (loc > 2) {
            p = p->link;
            loc--;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}
