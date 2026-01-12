/* Simple linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// append a Node to Simple Linked List
void append();
// append a value at begining
void add_at_begin();
void add_at_after();
void lengthLinkedList();
void traverseLinkedList();
void deleteNode();
void debug();

/* Node */
struct Node {
    // data of the node
    int data;
    // link to another node
    struct Node *next;
};

struct Node *root = NULL;

int main(void) {

    printf("Simple Linked List\n\n");

    int ch;
    while (1) {
        printf("1. Append\n");
        printf("2. Add at begining\n");
        printf("3. Add at nth position\n");
        printf("4. Length\n");
        printf("5. Travese\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if(scanf("%d",&ch) != 1) {
            return 0;
        }

        switch (ch) {
        case 1: append(); break;
        case 2: add_at_begin(); break;
        case 3: add_at_after(); break;
        case 4: lengthLinkedList(); break;
        case 5: traverseLinkedList(); break;
        case 6: deleteNode(); break;
        case 69: debug(); break;
        case 7: exit(1);
        
        default: printf("\nInvalid Option\n\n");
        }
    }
}

void append() {
    struct Node *tmp;
    tmp = malloc(sizeof(struct Node));
    printf("\nEnter node data: ");
    if(scanf("%d", &tmp->data) != 1) {
        free(tmp);
    }
    tmp->next = NULL;

    if(root == NULL) { // List is empty
        root = tmp;
    } else {
        struct Node *p;
        p = root;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void add_at_begin()
{
}

void add_at_after()
{
}

void lengthLinkedList() {
    int count = 0;
    struct Node *tmp;
    tmp = root;
    while (tmp != NULL) {
        ++count;
        tmp = tmp->next;
    }
    printf("\nLength of the Linked List is: %d\n\n",count);
}

void traverseLinkedList() {
    printf("\n");
    struct Node *tmp;
    tmp = root;
    if(tmp == NULL) {
        printf("List is empty -> Null\n");
    } else {
        while (tmp != NULL) {
            printf("%d->",tmp->data);
            tmp = tmp->next;
        }
        printf("NULL\n\n");
    }
}

void deleteNode()
{
}

void debug() {
    printf("\n------------------------Debug------------------------\n\n");
    lengthLinkedList();
    traverseLinkedList();
    printf("\nSize of each node: %ld\n\n",sizeof(struct Node));
    struct Node *tmp;
    tmp = root;
    printf("\namalloc_unusable_size: %ld\n\n",malloc_usable_size(tmp));
    if(tmp == NULL) {
        printf("List is empty -> Null\n");
    } else {
        while (tmp != NULL) {
            printf("%p->",(void *)tmp);
            tmp = tmp->next;
        }
        printf("Null");
    }
    printf("\n\n------------------------End-Debug------------------------\n\n");
    
}
