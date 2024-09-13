#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

int len(node *head){
    int i=0;
    node *temp = head;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


node* insertAtBeg(node *head, int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    return temp;
}


node* insertAtEnd(node *head, int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        // If the list is empty, the new node is the head
        return temp;
    }

    node *traverse = head; // Start from the head node
    // Traverse to the last node
    while(traverse->next != NULL){
        traverse = traverse->next;
    }

    // Set the next of the last node to the new node
    traverse->next = temp;

    return head;
}


node* insertBetween(node *head, int value, int index){
    if(index < 0 || index > len(head)){
        printf("Index out of bounds\n");
        return head;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;

    if(index == 0){
        // Insertion at the beginning
        temp->next = head;
        return temp; // New head
    }

    node *traverse = head;
    for(int i = 0; i < index - 1; i++){
        traverse = traverse->next;
    }

    // Insertion between nodes
    temp->next = traverse->next;
    traverse->next = temp;

    return head;
}



int main(){
    node *head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->next = NULL;

    head = insertAtBeg(head, 54);
    head=insertAtEnd(head,43);
    head=insertBetween(head,39,2);
    
    display(head);

    return 0;
}
