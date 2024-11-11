#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to separate even and odd nodes
void separateEvenOdd(struct Node* head, struct Node** evenList, struct Node** oddList) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            appendNode(evenList, current->data);
        } else {
            appendNode(oddList, current->data);
        }
        current = current->next;
    }
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* evenList = NULL;
    struct Node* oddList = NULL;

    // Create linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);

    printf("Original List:\n");
    printList(head);

    // Separate even and odd nodes
    separateEvenOdd(head, &evenList, &oddList);

    printf("\nEven List:\n");
    printList(evenList);

    printf("\nOdd List:\n");
    printList(oddList);

    return 0;
}
