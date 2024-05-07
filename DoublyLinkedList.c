#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;  
};

void DoublyLinkedListTraversal(struct Node *head){
    struct Node *p=head;
    while(p->next!=NULL){
        printf("Element is: %d\n",p->data);
        p=p->next;
    }
    printf("Element is: %d\n",p->data);
}

void DoublyLinkedListTraversalReversal(struct Node *head){
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    while(p->prev!=NULL){
        printf("Element is : %d\n",p->data);
        p=p->prev;
    }
            printf("Element is : %d\n",p->data);
}


struct Node * insertAtstart(struct Node *head,int element){
        struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
        ptr->data=element;
        ptr->next=head;
        ptr->prev=NULL;
        head=ptr;

        return head;
}


struct Node * insertAtindex(struct Node *head,int element ,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=element;
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;
    p->next->prev=ptr;
    return head;
}

struct Node *insertAtLast(struct Node *head,int element){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=element;
    ptr->next=NULL;
    ptr->prev=p;
    p->next=ptr;
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


head->data=7;
head->prev=NULL;
head->next=second;

second->data=2;
second->prev=head;
second->next=third;

third->data=9;
third->prev=second;
third->next=fourth;

fourth->data=5;
fourth->prev=third;
fourth->next=NULL;


printf("......\n");
DoublyLinkedListTraversal(head);
printf("Now reverse\n\n");
DoublyLinkedListTraversalReversal(head);


printf("Insertion at start\n");
head=insertAtstart(head,10);
DoublyLinkedListTraversal(head);

printf("Insertion at a index\n");
head=insertAtindex(head,12,3);
DoublyLinkedListTraversal(head);

printf("Insert at last\n");
head=insertAtLast(head,15);
DoublyLinkedListTraversal(head);


return 0;
}