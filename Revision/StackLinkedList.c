#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}stack;

stack* createnode(){
    stack *newnode = (stack*)malloc(sizeof(stack));
    int data;
    printf("Enter data\n");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

stack* push(stack *head){
    stack *newnode = createnode();
    newnode->next = head;  // Push to the top
    head = newnode;  // Update head to new node
    return head;
}

stack* pop(stack *head){
    if(head == NULL){
        printf("Can't delete from Empty stack\n");
        return head;
    }
    stack *tmp = head;
    printf("Element deleted is %d\n", tmp->data);
    head = head->next;  // Update head to next node
    free(tmp);  // Free the popped node
    return head;
}

void display(stack *head){
    if(head == NULL){
        printf("Stack is Empty\n");
        return;
    }
    stack *tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void isEmpty(stack *head){
    if(head == NULL){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is Not Empty\n");
    }
}

int top(stack *head){
    if(head == NULL){
        printf("Empty stack\n");
        return -1;
    }
    return head->data;
}

int main(){
    stack *head = NULL;
    while(true){
        int choice;
        printf("What do you want to do\n1.Push\n2.Pop\n3.Display stack\n4.IsEmpty\n5.Peek Top\n6.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                head = push(head);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                isEmpty(head);
                break;
            case 5:
                printf("Top Element is %d\n", top(head));
                break;
            case 6:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
}
