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



struct Node * deleteFirst(struct Node *head){
    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node *ptr = head;      // Store the reference to the first node
    head = head->next;            // Update head to point to the second node
    free(ptr);                    // Free the memory of the first node
    return head;                  // Return the updated head
}

struct Node * deleteUsingindex(struct Node *head,int index){
    struct Node *p=head;
    struct Node*q=head->next;    // jo index ka node delete krna tha usme pointer banaya
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;     // phir jo node delete karni h usse pehle wali node ko uske baad wali node se link kiya
    free(q);     // phir apna node delete kar diya       
    return head;
}

struct Node * deleteLast(struct Node *head){
         struct Node *p=head;
    struct Node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;       
    free(q);
    return head;
}


struct Node *deleteCertainNode(struct Node *head, int element) {
    struct Node *p = head;
    struct Node *q = head->next;

    while (q!= NULL && q->data!= element) {
        p = q;
        q = q->next;
    }

    if (q!= NULL) {
        p->next = q->next;
        free(q);
        printf("Deletion Successful\n");
    } else {
        printf("Deletion Unsuccessful\n");
    }

    return head;
}


int main(){
   

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node)); 
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=4; 
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=NULL;

 
    // Linked list before deletion.
    LinkedListTraversal(head);  

    // Linked List after deleting first element.
    head=deleteFirst(head);
    LinkedListTraversal(head);

    // Linked List deleting using index.
    head=deleteUsingindex(head,1);
    LinkedListTraversal(head);

    // Linked List deletion of last index/
    head=deleteLast(head);
    LinkedListTraversal(head);
    

    // Linked List Deletion of Certain Node
    head=deleteCertainNode(head,3);
    LinkedListTraversal(head);

    return 0;
}