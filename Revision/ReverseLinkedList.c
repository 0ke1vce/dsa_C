#include <stdio.h>
#include <stdlib.h>

// Definition of the Node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list without using double pointers
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;  // Keeps track of the previous node
    struct Node* curr = head;  // Points to the current node being processed
    
    while (curr != NULL) {
        struct Node* next = curr->next;  // Store the next node
        curr->next = prev;               // Reverse the link
        prev = curr;                     // Move prev one step forward
        curr = next;                     // Move curr one step forward
    }
    
    return prev;  // Return the new head (prev is now the first node)
}

// Function to push a node at the beginning of the list
struct Node* push(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;  // Point the new node to the current head
    head = new_node;        // Update head to the new node
    return head;            // Return the new head
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the reverse function
int main() {
    struct Node* head = NULL;
    
    // Create linked list 1->2->3->4->5
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    
    printf("Original Linked List:\n");
    printList(head);
    
    // Reverse the linked list
    head = reverse(head);
    
    printf("Reversed Linked List:\n");
    printList(head);
    
    return 0;
}


/*




*/