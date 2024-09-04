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

struct Node * insertAtFirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));     // ek node banayi jisme data h or next node ka adress hai 
    ptr->data=data;  
    ptr->next=head;  // us node k next m first node ka adress hogya
    head=ptr;       //now first node that is head node ko update kar diya ptr say means ki ab head node ptr hai
    return head;       // phir head node return kardi
}


struct Node * insertAtIndex(struct Node *head,int data,int index){
     struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));     // ek node banayi jisme data h or next node ka adress hai 
     struct Node *p=head;
     int i=0;
     while(i!=index-1){    //iteration karte rahe h or index-1 esliye rakha h kyuki jo index m hame insertion karna h to usse pehle k node m hame p pointer cahiye
        p=p->next;
        i++;
     }

     ptr->data=data;      //value rakh di apne node m 
     ptr->next=p->next;         // jo next element h usse link ho jayega apna node
     p->next=ptr;       // phir jo apna previous node h vo inserted node k saath link ho jayega
     return head;
}


struct Node * insertAtLast(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;  // to start our iteration from start to last node.
    while(p->next!=NULL){       
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;   //to get end of list we use NULL
    p->next=ptr;     
    return head;
    

}

struct Node * insertAfterNode(struct Node *head,struct Node *previousNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data =data;
    ptr->next=previousNode->next;
    previousNode->next=ptr;   
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

    head->data=8;
    head->next=second;

    second->data=7;
    second->next=third;

    third->data=11;
    third->next=fourth;

    fourth->data=10;
    fourth->next=NULL;

    // Our node before insertion at beginning
    LinkedListTraversal(head);

    // Our node after insertion  at beginning
    head=insertAtFirst(head,9);  //because this function is returning new head as head node is  keep updating
    LinkedListTraversal(head);
    

    // Our node after insertion in between ;
    head=insertAtIndex(head,69,2);     // not work for zeroth index that is beginning
    LinkedListTraversal(head);

    // Our node after insertion at last;
    head=insertAtLast(head,96);
    LinkedListTraversal(head);

    // Insert after a Node
    head=insertAfterNode(head,third,106);
    LinkedListTraversal(head);
    
    

    return 0;
}   