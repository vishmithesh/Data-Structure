#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertNode(struct Node** head, int data, int position);
void deleteNode(struct Node** head, int key);
void display(struct Node* head);
void sortList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert by Position\n");
        printf("2. Delete by Value\n");
        printf("3. Display List\n");
        printf("4. Sort List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert (1 for beginning): ");
                scanf("%d", &position);
                insertNode(&head, value, position);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                sortList(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode; 
        } else {
            struct Node* last = (*head)->prev;

            newNode->next = *head;
            newNode->prev = last;
            last->next = newNode;
            (*head)->prev = newNode;
            *head = newNode;
        }
        printf("Node with value %d inserted at position %d.\n", data, position);
    } else {
        struct Node* temp = *head;
        int count = 1;

        while (count < position - 1 && temp->next != *head) {
            temp = temp->next;
            count++;
        }

        if (count == position - 1) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            printf("Node with value %d inserted at position %d.\n", data, position);
        } else {
            printf("Invalid position!\n");
            free(newNode);
        }
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;

    if ((*head)->data == key) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            printf("Node with value %d deleted.\n", key);
            return;
        }

        struct Node* last = (*head)->prev;

        last->next = (*head)->next;
        (*head)->next->prev = last;
        temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }
    do {
        temp = temp->next;
    } while (temp != *head && temp->data != key);
    if (temp->data == key) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("Node with value %d deleted.\n", key);
    } else {
        printf("Node with value %d not found.\n", key);
    }
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *current, *index;
    int tempData;
    do {
        current = head;
        index = current->next;

        while (index != head) {
            if (current->data > index->data) {
                tempData = current->data;
                current->data = index->data;
                index->data = tempData;
            }
            current = current->next;
            index = index->next;
        }
        head = head->next;
    } while (head->next != current);

    printf("List sorted.\n");
}
