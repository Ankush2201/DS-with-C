#include <stdio.h>
#include <stdlib.h>
#define max 5

int Q[max];
int f = -1;
int r = -1;

void enQue(int value) {
    if (r == max - 1 ) {
        printf("Queue Overflow\n");
    } else if (f == r && r == -1) {
        f = r = 0;
        Q[r++] = value;
    } else {
        Q[r++] = value;
    }
}

int DeQue() {
    int val;
    if (f ==-1 || f > r ) {
        printf("Queue underflow\n");
        f = r = -1 ;
        return -1;
    }
    else if ( f == r){
        val = Q[f];
        f = r = -1 ;
    } else {
        val = Q[f];
        f++; 
    }
    return val;
}

int peek() {
    int val;
    if (r < f) {
        printf("Queue underflow\n");
        return -1;
    } else {
        val = Q[f];
    }
    return val;
}


void printQueue() {
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = f; i < r; i++) {
            printf("%d -> ", Q[i]);
        }
        printf("NULL\n");
    }
}


int main() {
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enQue(value);
                break;
            case 2:
                value = DeQue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Front of the queue: %d\n", value);
                }
                break;
            case 4:
                printQueue();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
