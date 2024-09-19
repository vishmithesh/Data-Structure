#include <stdio.h>
#include <stdlib.h>

int size;
int *arr;
int front = -1, rear = -1;

int isfull() {
    if ((rear + 1) % size == front) {
        return 1;  // Queue is full
    }
    return 0;
}

int isempty() {
    if (front == -1 && rear == -1) {
        return 1;  // Queue is empty
    }
    return 0;
}

void enqueue(int c) {
    if (isfull()) {
        printf("Cannot insert. Queue is full\n");
    } else {
        if (front == -1) {  // First insertion
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = c;
        printf("%d inserted into the queue\n", c);
    }
}

void dequeue() {
    if (isempty()) {
        printf("Cannot delete. Queue is empty\n");
    } else if (front == rear) {  // Only one element
        printf("Dequeued: %d\n", arr[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued: %d\n", arr[front]);
        front = (front + 1) % size;
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d\t", arr[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", arr[rear]);
    }
}

int main() {
    int choice, value;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("The given choice is invalid\n");
        }
    } while (choice != 0);

    free(arr);  // Free allocated memory
    return 0;
}
