#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

// Function to create a new node
node* createnode(){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;
    int Data;
    printf("Enter data in node: ");
    scanf("%d", &Data);
    newnode->data = Data;
    return newnode;
}

// Function to display the doubly linked list
void Display(node *head) {
    if(head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to calculate the length of the linked list
int len(node *head) {
    int count = 0;
    node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a node at the beginning of the list
node* InsertionBeginning(node *head) {
    node *newnode = createnode();
    if (head != NULL) {
        newnode->next = head;
        head->prev = newnode;
    }
    return newnode;  // New node becomes the head
}


// Function to insert a node at the end of the list
node* InsertionEnd(node *head) {
    node *newnode = createnode();
    if (head == NULL) {
        // If the list is empty, newnode becomes the head
        return newnode;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}


// Function to insert element at a index
node* InsertionAtIndex(node *head) {
    node *newnode=createnode();
    node* ptr=head;
    int index;
    printf("Enter the index: ");
    scanf("%d",&index);
    if(index<0||index>=len(head)){
        printf("Enter valid index");
        return head;
    }
    if(index==0){
        head=InsertionBeginning(head);
        return head;
    }
    for(int i=0;i<index-1;i++){
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    newnode->prev=ptr;
    (ptr->next)->prev=newnode;
    ptr->next=newnode;

    return head;

}


// Function to handle insertions (beginning, end)
node* insertion(node *head) {
    int choice;
    printf("Enter your choice:\n1. Insert at beginning\n2. Insert at end\n3. Insertion At Index\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            head = InsertionBeginning(head);
            break;
        case 2:
            head = InsertionEnd(head);
            break;

        case 3:
            head=InsertionAtIndex(head);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return head;
}

// Function to delete a node from the beginning of the list
node* DeletionBeginning(node *head) {
    node *tmp=head;
    head=head->next;
    free(tmp);
    head->prev=NULL;
    return head;
}

// Function to delete a node from the end of the list
node* DeletionEnd(node *head) {
    node *tmp=head;
    node *prev=head;
    while(tmp->next != NULL){
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next=NULL;
    free(tmp);
    return head;
}

node *DeletionIndex(node *head){

    if(head==NULL){
        printf("Nothing to delete -_-\n");
        return head;
    }
    int index;
    printf("Enter index to delete\n");
    scanf("%d",&index);

    if(index<0||index>=len(head)){
        printf("Invalid Index\n");
        return head;
    }
    if(index==0){
        head=DeletionBeginning(head);
        return head;
    }
    if(index==(len(head)-1)){
        head=DeletionEnd(head);
        return head;
    }

    node *tmp=head;
    node *curr=head->next;
    for(int i=0;i<index-1;i++){
        tmp=tmp->next;
        curr=curr->next;
}
    tmp->next=curr->next;
    (curr->next)->prev=tmp;
    free(curr);
    return head;
}

// Function to handle deletions (beginning, end)
node* deletion(node *head) {
    int choice;
    printf("Enter your choice:\n1. Delete from beginning\n2. Delete from end\n3. Delete from Index ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            head = DeletionBeginning(head);
            break;
        case 2:
            head = DeletionEnd(head);
            break;
        case 3:
            head=DeletionIndex(head);
            break;
        
        default:
            printf("Invalid choice.\n");
            break;
    }
    return head;
}

int main() {
    node *head = NULL;
    while(true) {
        int choice;
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertion(head);
                break;
            case 2:
                head = deletion(head);
                break;
            case 3:
                Display(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Enter a valid choice.\n");
                break;
        }
    }
    return 0;
}