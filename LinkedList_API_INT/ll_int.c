#include "ll_int.h"
#include <stdlib.h>
#include <stdio.h>

Node *root = NULL;

void append_ll_int(const int data) {
    Node *temp;
    temp = malloc(sizeof(Node));

    temp->data = data;
    temp->link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        Node *newNode;
        newNode = root;
        while (newNode->link != NULL) {
            newNode = newNode->link;
        }
        newNode->link = temp;
    }
}

void addatbegin_ll_int(const int data) {
    Node *temp;
    temp = malloc(sizeof(Node));

    temp->data = data;
    temp->link = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        temp->link = root;
        root = temp;
    }
}

void addatloc_ll_int(const int data, const int loc) {
    if(loc < 1 || loc > length_ll_int()) {
        printf("Invalid location!!\n\n");
        return;
    }

    if(loc == 1) {
        addatbegin_ll_int(data);
    } else if(loc == length_ll_int()) {
        append_ll_int(data);
    } else {
        Node *temp;
        temp = malloc(sizeof(Node));

        int c = loc;

        temp->data = data;
        temp->link = NULL;

        Node *newNode;
        newNode = root;
        while (c > 1) {
            newNode = newNode->link;
            c--;
        }
        temp->link = newNode->link;
        newNode->link = temp;
    }
}

void addatlmid_ll_int(const int data) {
    Node *temp;
    temp = malloc(sizeof(Node));

    temp->data = data;
    temp->link = NULL;

    int mid = length_ll_int()/2;

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

int length_ll_int() {
    Node *temp;
    temp = root;
    
    if(temp == NULL) {
        return 0;
    }

    int c = 0;
    while (temp != NULL) {
        c++;
        temp = temp->link;
    }
    
    return c;
}

void display_ll_int() {
    Node *temp;
    temp = root;
    if(temp == NULL) {
        printf("\nList is empty!!\n\n");
        return;
    }
    while (temp != NULL) {
        printf("%d-->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n\n");
    
}

void delete_ll_int(const int loc) {
    int c = loc;

    if(loc < 1 || loc > length_ll_int()) {
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
        while (c > 2) {
            p = p->link;
            c--;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    
}

void swapatloc_ll_int(const int loc) {
    int c = loc;

    if(c < 1 || c >= length_ll_int()) {
        printf("Invalid location!!\n\n");
        return;
    }

    Node *p, *q, *r;

    p=root;
    while (c > 2) {
        p = p->link;
        c--;
    }

    q = p->link;
    r = q->link;
    

    q->link = r->link;
    r->link = q;
    p->link = r;
}
