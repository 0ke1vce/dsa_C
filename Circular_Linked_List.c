#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void CircularListTraversal(struct Node *head){
    struct Node *ptr=head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

    printf("\n");

}

struct Node * InsertAtStartCircular(struct Node *head,int data){
      struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
      ptr->data=data;
      
      struct Node *p=head->next;
      while(p->next!=head){
        p=p->next;
      }
    //   At this point p points to the last node of this circular Linked List
    
    p->next=ptr;  //now last node links with new node

    ptr->next=head; //now new node links with head node
    head=ptr;    //now our new node become head node
    return head;

}

struct Node * InsertBetweenNodeCircular(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;        
    struct Node *q = head;

    // 2 Pointers banaye jo head ko point karrhe h 

    for (int i = 0; i < index - 1; i++) {
        p = p->next;      // ab p pointer ko jis index m node rakhni h usse pehle rakh diya
    }

    q = p->next;      // ab q pointer ko jo  p pointer h uske next node se link karwa diya

    p->next = ptr;      //PHIR P KO APNE INSERT KARNE WALE NODE SE LINK KARWAYA
    ptr->next = q;      // PHIR JO INSERTED NODE H USSE AGLE NODE SE LINK KARWA DIYA

    return head;
}

struct Node * InsertafterNode(struct Node *head,struct Node *node2,int data){
   struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head;
    while(p!=node2){
        p=p->next;
    }
    q=p->next;
    p->next=ptr;
    ptr->next=q;
    return head;

}
    


struct Node * DeleteFirstNode(struct Node *head){
    struct Node *p=head;
    head=head->next;
    free(p);

    struct Node *q=head;
    // Traverse the list to find the last node
    while(q->next!=p){
        q=q->next;
    }
    // Update the last node's next pointer to maintain circular link
    q->next=head;

    return head;
}

 struct Node *DeleteNodeofGivenIndex(struct Node *head,int index){
    struct Node *p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    struct Node *q=p->next;
    p->next=q->next;
    free(q);
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

    third->data=6;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;

    CircularListTraversal(head);


    printf("Insertion Operations\n");
    head=InsertAtStartCircular(head,80);
    CircularListTraversal(head);

    head=InsertBetweenNodeCircular(head,69,2);
    CircularListTraversal(head);

    head=InsertafterNode(head,third,52);
    CircularListTraversal(head);

    printf("Deletion Operations\n");
    head=DeleteFirstNode(head);
    CircularListTraversal(head);

    head=DeleteNodeofGivenIndex(head,2);
    CircularListTraversal(head);

    return 0;
}