#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int f = -1;
int r = -1;
int Qu[MAX];

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(int x) {
    if (r == (MAX - 1)) {
        printf("Q-->Queue Overflow<--Q\n");
    } else if (r == f && f == -1) {
        f = r = 0;
        Qu[r] = x;
    } else {
        r++;
        Qu[r] = x;
    }
}

int dequeue() {
    int v;
    if (f == -1 || f > r) {
        printf("Q-->Queue is Empty<--Q\n");
        return -1;
    } else if (f == r) {
        v = Qu[f];
        f = r = -1;
    } else {
        v = Qu[f];
        f++;
    }
    return v;
}

void display() {
    if (f == -1 || f > r) {
        printf("Q-->Queue is Empty<--Q\n");
    } else {
        printf("Queue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", Qu[i]);
        }
        printf("\n");
    }
}

int peek() {
    if (f == -1 || f > r) {
        printf("Q-->Queue is Empty<--Q\n");
        return -1;
    } else {
        return Qu[f];
    }
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue_link(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue_link(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

int peek_link(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->front->data;
}

void display_link(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice2;
    struct Queue* my_queue = createQueue();
    printf("Ankush pandey 60009230211");
    do {
        printf("Menu:\n1. Using array \n2. Using Linked list\n" "3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);

        switch (choice2) {
            case 1:
                int choice, value;
                do {
                    printf("\n----- Queue Menu -----\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Peek\n");
                    printf("5. Exit\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Note: Enter -1 to Exit Execution\n");
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &value);
                            while (value != -1) {
                                enqueue(value);
                                printf("Enter the value to enqueue: ");
                                scanf("%d", &value);
                            }
                            break;

                        case 2:
                            int x = dequeue();
                            if (x == -1) {
                                printf("No element in queue.\n");
                            } else {
                                printf("Dequeued Element %d\n", x);
                            }
                            break;

                        case 3:
                            display();
                            break;

                        case 4:
                            printf("Peek value: %d\n", peek());
                            break;

                        case 5:
                            printf("Exiting the program.\n");
                            break;

                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (choice != 5);
                break;

            case 2:
                int choice3, value1;
                do {
                    printf("\n----- Queue Menu -----\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Peek\n");
                    printf("4. Display\n");
                    printf("5. Exit\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice3);

                    switch (choice3) {
                        case 1:
                            printf("Enter the value to enqueue: ");
                            scanf("%d", &value1);
                            while (value1 != -1) {
                                enqueue_link(my_queue, value1);
                                printf("Enter the value to enqueue: ");
                                scanf("%d", &value1);
                            }
                            break;

                        case 2:
                            dequeue_link(my_queue);
                            break;

                        case 3:
                            printf("Peek value: %d\n", peek_link(my_queue));
                            break;

                        case 4:
                            display_link(my_queue);
                            break;

                        case 5:
                            printf("Exiting the program.\n");
                            break;

                        default:
                            printf("Invalid choice. Please enter a valid option.\n");
                    }
                } while (choice3 != 5);
                break;

            case 3:
                     printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");

        }

    } while (choice2 != 3);

    return 0;
}

