#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("element is : %d\n",ptr->data);  
    ptr=ptr->next;  // ab us pointer m next node ka adress store hogya h 
    }
    printf("\n");
}

int main(){
// Creating Linked list    

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocation memory for nodes in heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node)); 
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    
    // lINKING FIRST AND SECOND NODE
    head->data=45; 
    head->next=second;
    
    // lINKING SECOND AND THIRD NODE 
    second->data=98;
    second->next=third;
    
    // lINKING THIRD AND FOURTH NODE
    third->data=3;
    third->next=fourth;


    // TERMINATING THE LIST AT THE fourth NODE
    fourth->data=43;
    fourth->next=NULL;



// Calling function to traversal
LinkedListTraversal(head);  //head is a pointer of struct node * type ka

    return 0;
}