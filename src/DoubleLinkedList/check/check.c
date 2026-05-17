#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *left_link;
    struct Node *right_link;
} Node;

Node *root = NULL;

void DLL_append(void);
void DLL_addatbegin(void);
void DLL_addatmid(void);
void DLL_addatloc(void);
int DLL_length(void);
void DLL_display(void);
void DLL_delete(void);
void DLL_swapatloc(void);

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
        printf("8. Swap at loc\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("\n");
                DLL_append();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 2:
                printf("\n");
                DLL_addatbegin();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 3: 
                printf("\n");
                DLL_addatloc();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 4:
                printf("\n");
                DLL_addatmid();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 5:  
                printf("\nThe length of the linked list is: %d\n\n", DLL_length());
                break;

            case 6:
                printf("\nThe linked list is: ");
                DLL_display();
                break;

            case 7:
                printf("\n");
                DLL_delete();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 8:
                printf("\n");
                DLL_swapatloc();
                printf("The linked list is: ");
                DLL_display();
                break;

            case 9:
                printf("\nThe linked list is: ");
                DLL_display();
                exit(1);
                break;
            
            default: 
                printf("Invalid option!!!\n\n");
                break;
        }
    }

    return 0;
}

void DLL_append() {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->left_link = NULL;
    temp->right_link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        Node *newNode;
        newNode = root;
        while(newNode->right_link != NULL) {
            newNode = newNode->right_link;
        }
        newNode->right_link = temp;
        temp->left_link = newNode;
    }
}

void DLL_addatbegin(void) {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->left_link = NULL;
    temp->right_link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        root->left_link = temp;
        temp->right_link = root;
        root = temp;
    }
}

void DLL_addatmid(void) {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->left_link = NULL;
    temp->right_link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        int mid = DLL_length()/2;

        Node *pNode = root;
        while (mid > 1) {
            pNode = pNode->right_link;
            mid--;
        }
        pNode->right_link->left_link = temp;
        temp->right_link = pNode->right_link;
        temp->left_link = pNode;
        pNode->right_link = temp;
    }
}

void DLL_addatloc(void) {
    int loc;
    printf("Enter location: ");
    scanf("%d", &loc);

    int len = DLL_length();

    if(loc < 1 || loc > len) {
        printf("Invalid location!!\n\n");
        return;
    }

    if(loc == 1) {
        DLL_addatbegin();
    } else if(loc == len) {
        DLL_append();
    } else {
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));

        printf("Enter node data: ");
        scanf("%d", &temp->data);

        temp->left_link = NULL;
        temp->right_link = NULL;

        Node *pNode = root;
        while (loc > 1) {
            pNode = pNode->right_link;
            loc--;
        }
        pNode->right_link->left_link = temp;
        temp->right_link = pNode->right_link;
        temp->left_link = pNode;
        pNode->right_link = temp;
    }
}

int DLL_length(void) {
    Node *temp;
    temp = root;
    if(temp == NULL) {
        return 0;
    }
    int c = 0;
    while(temp != NULL) {
        c++;
        temp = temp->right_link;
    }
    return c;
}

void DLL_display(void) {
    Node *temp;
    temp = root;
    if(temp == NULL) {
        printf("\nList is empty!!\n\n");
        return;
    }
    while(temp != NULL) {
        printf("%d<==>",temp->data);
        temp = temp->right_link;
    }
    printf("NULL\n\n");
}

void DLL_delete(void) {
    int loc;
    printf("Enter location: ");
    scanf("%d", &loc);

    int len = DLL_length();

    if(loc < 1 || loc > len) {
        printf("Invalid location!!\n\n");
        return;
    }

    if(loc == 1) {
        Node *temp = root;
        root = temp->right_link;
        temp->right_link = NULL;
        free(temp);
    } else {
        Node *node = root;
        while (loc > 1) {
            node = node->right_link;
            loc--;
        }
        node->right_link->left_link = node->left_link->right_link;
        node->left_link->right_link = node->right_link;
        node->left_link = node->right_link = NULL;
        free(node);
    }
}

void DLL_swapatloc(void) {
    int loc;
    printf("Enter location: ");
    scanf(" %d", &loc);

    if(loc < 1 || loc >= DLL_length()) {
        printf("Invalid location!!\n\n");
        return;
    }

    Node *curr = root;
    while (loc > 1) {
        curr = curr->right_link;
        loc--;
    }
    
    Node *next = curr->right_link;

    if(next == NULL) {
        printf("Can't swap!\n\n");
        return;
    }

    Node *prev = curr->left_link;
    Node *after = next->right_link;

    if(prev != NULL) {
        prev->right_link = next;
    } else {
        root = next;
    }

    next->left_link = prev;
    next->right_link = curr;

    curr->left_link = next;
    curr->right_link = after;

    if(after != NULL) {
        after->left_link = curr;
    }
}
