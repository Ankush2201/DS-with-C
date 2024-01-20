#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *Insert_Element(struct node *start) {
    int data, pri;
    printf("Enter -1 to Exit\n");
    printf("Enter the Number: ");
    scanf("%d", &data);
    printf("Enter the priority: ");
    scanf("%d", &pri);

    while (data != -1) {
        struct node *Newnode = malloc(sizeof(struct node));
        Newnode->data = data;
        Newnode->priority = pri;
        Newnode->next = NULL;

        if (start == NULL || start->priority > pri) {
            Newnode->next = start;
            start = Newnode;
        } else {
            struct node *ptr = start;
            while (ptr->next != NULL && ptr->next->priority >= pri) {
                ptr = ptr->next;
            }
            Newnode->next = ptr->next;
            ptr->next = Newnode;
        }

        printf("Enter the Number: ");
        scanf("%d", &data);

        if (data == -1) {
            break;
        }

        printf("Enter the priority: ");
        scanf("%d", &pri);
    }

    return start;
}


struct node *delete (struct node *start) {
    if (start == NULL) {
        printf("Queue is Underflow\n");
    } else {
        struct node *ptr = start;
        printf( " element Deleted %d" , ptr ->data);
        start = start->next;
        free(ptr);
    }
    return start;
}

struct node *display(struct node *start) {
    if (start == NULL) {
        printf("Queue is Underflow\n");
    } else {
        struct node *ptr = start;
        printf("Queue is:\n");
        while (ptr != NULL) {
            printf("\t%d | p-> %d\n", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }
    return start;
}

int main() {
    struct node *start = NULL;
    int choice;

    do {
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Display Queue");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = Insert_Element(start);
                break;
            case 2:
                start = delete (start);
                break;
            case 3:
                start = display(start);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
