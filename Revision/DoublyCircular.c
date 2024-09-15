#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

void display(node *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    node *tmp = head;
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while(tmp != head);
    printf("\n");
}


int len(node *head){
    if(head == NULL) return 0; // Handle empty list
    node *tmp = head;
    int len = 0;
    do {
        len++;
        tmp = tmp->next;
    } while(tmp != head);
    return len;
}


node *createnode(){
    node *newnode=(node *)malloc(sizeof(node));
    int data;
    printf("Enter data in your node\n");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}


void Searching(node *head){
    int data;
    printf("Enter data to search\n");
    scanf("%d", &data);
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *tmp = head;
    int i = 0;
    do {
        if(tmp->data == data){
            printf("Found at index %d\n", i);
            return;
        }
        i++;
        tmp = tmp->next;
    } while(tmp != head);
    printf("Not found\n");
}

node *InsertionBeg(node *head){
    node *newnode = createnode();
    if(head == NULL){
        head = newnode;
        head->next = head;
        head->prev = head;
    } 
    else {
        node *tail = head->prev;  // Get the last node
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;  // New node becomes the head
    }
    return head;
}


node *InsertionEnd(node *head) {
    node *newnode = createnode();
    
    if(head == NULL) {
        // If the list is empty, new node points to itself (circular list with one element)
        head = newnode;
        head->next = head;
        head->prev = head;
    } else {
        // Get the last node (tail)
        node *tail = head->prev;
        
        // Update the pointers for the new node and the existing nodes
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
    return head;
}

node *InsertionInd(node *head) {
    node *newnode = createnode();
    int index;
    
    printf("Enter index to insert element\n");
    scanf("%d", &index);
    
    int listLength = len(head);  // Store the length once
    
    // Check for invalid index
    if (index < 0 || index > listLength) {
        printf("Invalid index\n");
        return head;
    }
    
    // Insert at the beginning
    if (index == 0) {
        return InsertionBeg(head);
    }
    
    // Insert at the end
    if (index == listLength) {
        return InsertionEnd(head);
    }
    
    // Insert in the middle
    node *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    
    // Update pointers to insert newnode in the list
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    
    return head;
}



node *Insertion(node *head){
    int choice;
    printf("What do you want to do\n1.Insertion Begining\n2.Insertion End\n3.Insertion At Index");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            head=InsertionBeg(head);
            break;
        case 2:
            head=InsertionEnd(head);
            break;
        case 3:
            head=InsertionInd(head);
            break;
        default:
            printf("enter a valid choice\n");
            break;
    }
    return head;
}

node *DeletionBeg(node *head){
    if(head==NULL){
        printf("List is Empty\n");
        return head;
    }
    node *tmp=head;
    head=head->next;
    (tmp->prev)->next=head;
    head->prev=(tmp->prev);
    free(tmp);
    return head;
}

node *DeletionEnd(node *head){
    if(head==NULL){
        printf("list is empty\n");
        return head;
    }
    node *tmp=head->prev;
    node *tmp_prev=tmp->prev;
    tmp_prev->next=head;
    head->prev=tmp_prev;
    free(tmp);
    return head;
}


node *DeletionInd(node *head){
    if(head==NULL){
        printf("list is empty\n");
        return NULL;
    }
    int index;
    printf("Enter index to delete\n");
    scanf("%d",&index);

    if(index<0||index>len(head)){
        printf("invalid index\n");
        return head;
    }

    if(index==0){
        return DeletionBeg(head);
    }

    if(index==len(head)){
        return DeletionEnd(head);
    }

    node *tmp=head;
    for(int i=0;i<index-1;i++){
        tmp=tmp->next;
    }
    node *tmp_nxt=tmp->next;
    tmp->next=tmp_nxt->next;
    (tmp_nxt->next)->prev=tmp;
    free(tmp_nxt);
    return head;
}

node *Deletion(node *head){
    int choice;
    printf("What do you want to do\n1.Deletion Begining\n2.Deletion End\n3.Deletion At Index");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            head=DeletionBeg(head);
            break;
        case 2:
            head=DeletionEnd(head);
            break;
        case 3:
            head=DeletionInd(head);
            break;
        default:
            printf("enter a valid choice\n");
            break;
    }
    return head;
}



int main(){
    node *head=NULL;
    while(true)
    {
        int choice;
        printf("What do you want to do\n1.Insertion\n2.Deletion\n3.Searching\n4.Display\n5.Exit\n");
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
            Searching(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Exiting the program\n");
            return 0;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
    
}