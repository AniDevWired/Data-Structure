#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ll_int.h"

int main(void) {

    int ch;
    int data;
    int loc;
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
                printf("Enter a data: ");
                scanf(" %d", &data);
                append_ll_int(data);
                printf("\n");
                break;

            case 2: 
                printf("Enter a data: ");
                scanf(" %d", &data);
                addatbegin_ll_int(data);
                printf("\n");
                break;

            case 3: 
                printf("Enter a data: ");
                scanf(" %d", &data);
                printf("\nEnter a location: ");
                scanf(" %d", &loc);
                addatloc_ll_int(data, loc);
                printf("\n");
                break;

            case 4: 
                printf("Enter a data: ");
                scanf(" %d", &data);
                addatlmid_ll_int(data);
                printf("\n");
                break;

            case 5:  
                printf("\nThe length of the linked list is: %d\n\n", length_ll_int());
                break;

            case 6:  
                display_ll_int();
                break;

            case 7:
                printf("Enter a location: ");
                scanf(" %d", &loc);
                delete_ll_int(loc);
                printf("\n");
                break;

            case 8: 
                printf("Enter a location: ");
                scanf(" %d", &loc);
                swapatloc_ll_int(loc);
                printf("\n");
                break;

            case 9: 
                exit(1);
                break;
            
            default: 
                printf("Invalid option!!!\n\n");
                break;
        }
    }

    return 0;
}
