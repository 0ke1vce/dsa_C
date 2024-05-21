/*

Given a Singly Linked List, the task is to find the middle of the linked list. If the number of nodes are even, then there would be two middle nodes, so return the second middle node.

Example:

Input: linked list = 1 -> 2 -> 3 -> 4 -> 5
Output: 3 
Explanation: There are 5 nodes in the linked list and there is one middle node whose value is 3.

Input: linked list = 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 4 
Explanation: There are 6 nodes in the linked list, so we have two middle nodes: 3 and 4, but we will return the second middle node which is 4.

*/
#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
 };


void middleNode(struct node *head, int n) {
    printf("Middle Node is->\n");
    struct node *temp = head;
    int i = 0;
    while (i < n / 2) {
        temp = temp->next;
        i++;
    }
    if (n % 2 == 0) {
        temp = temp->next;
    }
    printf("Element at middle is %d\n", temp->data);
}

int main(){
    int no_of_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d",&no_of_nodes);
    
    struct node *head,*newnode,*temp;
    head==NULL;

    for(int i=0;i<no_of_nodes;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    middleNode(head,no_of_nodes);

    return 0;
}