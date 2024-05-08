#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};


int isEmpty(struct Stack *ptr){
    if(ptr->top==-1){
        return 1;   //True means stack is empty
    }
    else{
        return 0;
    }
}

int isFull(struct Stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;   //True means stack is full
    }
    else{
        return 0;
    }
}

void push(struct Stack *s,int element){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    else{
        s->top++;
        s->arr[s->top]=element;
    }
}

void Display(struct Stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d\n",s->arr[i]);
    }
}

int peek(struct Stack *s){
     // Check if stack is Empty
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    
    else{
        int top=s->arr[s->top];
        return top;
    }
}

void pop(struct Stack *s){
    s->top--;
}

int main(){
  
   struct Stack *s = malloc(sizeof(struct Stack)); // Allocate memory for the struct
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error
    }

    s->size = 30;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));


    // Check if stack is Empty
  /*
    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is Not empty\n");
    }
*/

    // Check if stack is full
 /*
    if(isFull(s)){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is Not full\n");
    }
    */

    // Push Operation
    push(s,56);
    push(s,32);
    push(s,97);
    push(s,52);
    push(s,69);
    
    // Display our stack
    Display(s);

    // TO peek our Top or last index
    int top=peek(s);
    printf("Top element is %d\n",top);


// TO pop element from stack
    pop(s);
    pop(s);

    // Display our stack
    Display(s);

// TO display TOP
    top=peek(s);
    printf("Top element is %d\n",top);

return 0;
}