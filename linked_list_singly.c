#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a linked list
struct node* create_ll(struct node* start) {
    int val;
    printf("Enter -1 to exit Creation");
    printf("\nEnter Element: ");
    scanf("%d", &val);

    while (val != -1) {
        struct node* nn = (struct node*)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;

        if (start == NULL) {
            start = nn;
        } else {
            struct node* ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = nn;
        }

        printf("Enter Element: ");
        scanf("%d", &val);
    }
    return start;
}

// Function to insert at the beginning
struct node* insert_beg(struct node* start) {
    int val;
    printf("\nEnter Element: ");
    scanf("%d", &val);

    struct node* nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    start = nn;

    return start;
}

// Function to display the linked list
struct node* display(struct node* start) {
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct node* ptr = start;
        while (ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    return start;
}

// Function to delete a specific element
struct node* delete_element(struct node* start) {
    struct node* ptr;
    struct node* preptr;
    int val;
    printf("\nEnter Element to Delete: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while ( ptr!=NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
            printf("Element not found\n");
            return start;
        }
    preptr->next = ptr->next;
    free(ptr);
    printf("Element %d deleted successfully\n", val);
    return start;
}

// Function to sort the linked list in descending order
struct node* sort(struct node* start) {
    struct node* ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr2->data > ptr1->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}

// Function to reverse the linked list
struct node* reverse(struct node* start) {
    struct node* prev = NULL;
    struct node* current = start;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    start = prev;
    return start;
}

// Function to delete after a specific element
struct node* deleteAfter(struct node* start) {
    struct node* ptr;
    struct node* preptr;
    int val;
    printf("\nEnter Element after which deletion should occur: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("Element not found\n");
            return start;
        }
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("Element after %d deleted successfully\n", val);
    return start;
}

// Function to insert at the end
struct node* insertEnd(struct node* start) {
    int val;
    printf("\nEnter Element: ");
    scanf("%d", &val);

    struct node* nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;

    if (start == NULL) {
        start = nn;
    } else {
        struct node* ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = nn;
    }

    return start;
}

// Function to insert after a specific element
struct node* insertAfter(struct node* start) {
    int val, afterVal;
    printf("\nEnter Element after which insertion should occur: ");
    scanf("%d", &afterVal);

    struct node* ptr = start;
    while (ptr != NULL && ptr->data != afterVal) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Element not found\n");
        return start;
    }

    printf("\nEnter Element: ");
    scanf("%d", &val);

    struct node* nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = ptr->next;
    ptr->next = nn;

    return start;
}

// Function to delete from the end
struct node* deleteEnd(struct node* start) {
    if (start == NULL) {
        printf("Linked list is empty\n");
        return start;
    }

    struct node* ptr = start;
    struct node* preptr = NULL;

    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (preptr == NULL) {
        free(ptr);
        start = NULL;
    } else {
        preptr->next = NULL;
        free(ptr);
    }

    printf("Element deleted from the end successfully\n");
    return start;
}

int main() {
    struct node* start = NULL;
    int choice;

    do {
        printf("\n1. Create a linked list");
        printf("\n2. Insert at the beginning");
        printf("\n3. Display");
        printf("\n4. Delete a specific element");
        printf("\n5. Sort in descending order");
        printf("\n6. Reverse");
        printf("\n7. Delete after a specific element");
        printf("\n8. Insert at the end");
        printf("\n9. Insert after a specific element");
        printf("\n10. Delete from the end");
        printf("\n11. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create_ll(start);
                break;
            case 2:
                start = insert_beg(start);
                break;
            case 3:
                start = display(start);
                break;
            case 4:
                start = delete_element(start);
                break;
            case 5:
                start = sort(start);
                break;
            case 6:
                start = reverse(start);
                break;
            case 7:
                start = deleteAfter(start);
                break;
            case 8:
                start = insertEnd(start);
                break;
            case 9:
                start = insertAfter(start);
                break;
            case 10:
                start = deleteEnd(start);
                break;
            case 11:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 11);

    return 0;
}
