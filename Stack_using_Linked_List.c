#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100


struct node{
    int data;
    struct node *next;
};

int size_stack(struct node *s){
    int size=0;
    struct node *ptr=s;
    while(ptr!=NULL){
        ptr=ptr->next;
        size++;
    }
    return size;
}

void LinkedListTraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("element is : %d\n",ptr->data);  
        ptr=ptr->next;  // ab us pointer m next node ka adress store hogya h 
    }
    printf("\n");
}


void push(struct node **s, int element) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack Overflow\n");
    }

    temp->data = element;
    temp->next = *s;

    *s = temp;
    return;
}

void pop(struct node **head) {
    if (*head == NULL) {
        printf("Can't Delete\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void isEmpty(struct node **s){
    if(*s == NULL){
        printf("Stack is Empty\n");
    }
}

void isFull(struct node **s){
   struct node *n=(struct node *)malloc(sizeof(struct node));
   if(n==NULL){
    printf("Creation error means stack is full\n");
   }
   else{
    printf("Stack is not full\n");
   }
}

void stacktop(struct node *s){
    printf("Top element is %d\n",s->data);
}

void stackBottom(struct node *s){
    struct node *temp=s;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Bottom element is %d\n",temp->data);
}

int peek(struct node *top, int pos) {
    if (top == NULL) {
        return -1;
    }
    if (pos < 1 || pos > size_stack(top)) {
        return -1;
    }
    struct node *ptr = top;
    for (int i = 0; i < pos - 1; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}


int main(){

    struct node *head = (struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=NULL;

    printf("Linked List before any operations\n");
    printf("______________________________________");
    LinkedListTraversal(head);


    printf("Linked List after some operations\n");
    printf("__________________________________________");
   int element;
   printf("Enter element to push\n");
   scanf("%d", &element);
   push(&head, element);
   LinkedListTraversal(head);

     printf("Enter element to push\n");
   scanf("%d", &element);
   push(&head, element);
   LinkedListTraversal(head);

  /*
   pop(&head);
      LinkedListTraversal(head);
   pop(&head);
      LinkedListTraversal(head);
   pop(&head);
      LinkedListTraversal(head);
   isEmpty(&head);
*/
    stacktop(head);
    stackBottom(head);

    int size= size_stack(head);
    printf("Size of stack is %d\n",size);

    isFull(&head);

    int ele=peek(head,3);
    printf("element peeked is  -> %d\n",ele);

    return 0;
}