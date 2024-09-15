#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createnode(){
    node *newnode=(node *)malloc(sizeof(node));
    int data;
    printf("Enter data in  your node");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

int len(node *head) {
    if (head == NULL) return 0; // Handle empty list

    int count = 1;  // Start from 1, as head is the first node
    node *tmp = head->next;  // Start from the node after head

    while (tmp != head) {
        tmp = tmp->next;
        count++;
    }
    return count;
}


void display(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *tmp = head;
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
    printf("\n");
}


node* InsertionBeg(node* head) {
    node* newnode = createnode(); // Create the new node

    if (head == NULL) {
        // If the list is empty, point the new node to itself
        newnode->next = newnode;
        head = newnode;
    } else {
        // If the list is not empty, find the last node
        node* tmp = head;
        while (tmp->next != head) { // Circular condition
            tmp = tmp->next;
        }
        // Insert the new node at the beginning
        tmp->next = newnode;  // Last node points to new node
        newnode->next = head; // New node points to old head
        head = newnode;       // New node becomes the head
    }

    return head;
}


node* InsertionEnd(node* head) {
    node* newnode = createnode(); // Create the new node
    if (head == NULL) {
        // If the list is empty, the new node points to itself
        head = newnode;
        newnode->next = newnode;
    } else {
        // Traverse to the last node
        node* tmp = head;
        while (tmp->next != head) { // Circular condition
            tmp = tmp->next;
        }
        // Insert the new node at the end
        tmp->next = newnode;
        newnode->next = head; // New node points to head
    }
    return head;
}

node* InsertionIndex(node* head) {
    int index;
    printf("Enter index to insert\n");
    scanf("%d", &index);
    
    if (index < 0 || index >= len(head)) {
        printf("Invalid index\n");
        return head;
    }

    if (index == 0) {
        // Insert at the beginning
        return InsertionBeg(head);
    }

    if (index == len(head)) {
        // Insert at the end
        return InsertionEnd(head);
    }

    // Create the new node
    node* newnode = createnode();

    // Insert at the specified index
    node* tmp = head;
    for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;

    return head;
}



node* DeletionBeg(node* head) {
    if (head == NULL) {
        printf("Can't delete, Underflow\n");
        return head;
    }

    node* tmp = head;

    // Case: Only one node in the list
    if (head->next == head) {
        free(head);
        return NULL; // Return NULL as the list is now empty
    }

    // Traverse to the last node
    while (tmp->next != head) {
        tmp = tmp->next;
    }

    // Update pointers to bypass the head
    node* freen = head;
    head = head->next;
    tmp->next = head;

    free(freen); // Free the old head
    return head;
}


node* DeletionEnd(node* head) {
    if (head == NULL) {
        printf("Can't delete, Underflow\n");
        return head;
    }

    // If only one element
    if (head->next == head) {
        free(head);
        return NULL;
    }

    node* tmp = head;
    node* prev = NULL;

    // Traverse to find the last node and the node before it
    while (tmp->next != head) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Now, `tmp` is the last node, and `prev` is the second-to-last node
    prev->next = head; // Make second-to-last node point to the head

    free(tmp); // Free the last node

    return head;
}


node* DeletionIndex(node* head) {
    int index;
    printf("Enter your index to delete\n");
    scanf("%d", &index);

    if (head == NULL) {
        printf("Empty list\n");
        return head;
    }

    int length = len(head); // Calculate the length once

    if (index < 0 || index >= length) {
        printf("Invalid index\n");
        return head;
    }

    // If index is 0, delete the first node
    if (index == 0) {
        head = DeletionBeg(head);
        return head;
    }

    // If index is the last node, delete the last node
    if (index == length - 1) {
        head = DeletionEnd(head);
        return head;
    }

    // Traverse to find the node to delete
    node* tmp = head;
    node* prev = NULL;

    for (int i = 0; i < index; i++) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Update the previous node's next pointer
    prev->next = tmp->next;

    // Free the node to be deleted
    free(tmp);

    return head;
}

node *Insertion(node *head){
        int choice;
        printf("1.Insertion Begining\n2.Insertion End\n3.Insertion at Index\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                head=InsertionBeg(head);
                break;
            case 2:
                head=InsertionEnd(head);
                break;
            case 3:
                head=InsertionIndex(head);
                break;
            default:
                printf("enter valid choice\n");
                break;
        }
        return head;
}

node *Deletion(node *head){
         int choice;
        printf("1.Deletion Begining\n2.Deletion End\n3.Deletion at Index\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                head=DeletionBeg(head);
                break;
            case 2:
                head=DeletionEnd(head);
                break;
            case 3:
                head=DeletionIndex(head);
                break;
            default:
                printf("enter valid choice\n");
                break;
        }
        return head;
}



int main(){
    node *head=NULL;
    int choice;
    while(true){
        printf("Enter your choice\n1.Insertion\n2.Deletion\n3.Display\n4.Exiting\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            head=Insertion(head);
            break;
        case 2:
            head=Deletion(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Exiting the program\n");
            return 0;
            break;
        default:
            printf("Enter a valid choice");
            break;
        }
    }

}