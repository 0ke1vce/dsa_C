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

void search(node *head,int value){
    node *temp = head;
    int flag=0;
    while(temp!=NULL){
        
        if(temp->data==value){
            flag=1;
            printf("Element %d found at position %d\n",value,len(head)-len(temp));
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("Element not found\n");
    }

}

int main(){
    node *head = (node *)malloc(sizeof(node));
    node *second=(node *)malloc(sizeof(node));
    node *third=(node *)malloc(sizeof(node));
    node *fourth=(node *)malloc(sizeof(node));


    head->data = 45;
    head->next = second;

    second->data=43;
    second->next=third;

    third->data=40;
    third->next=fourth;

    fourth->data=46;
    fourth->next=NULL;

    search(head, 40);

    

    return 0;
}
