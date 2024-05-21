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
    if(isFull(s)){    //means if this condition is true that is condition is 1-->TRUE
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

int peek(struct Stack *s,int element_number){
     // Check if stack is Empty
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    if(element_number<0){
        printf("Not a valid Position\n");
        return -1;
  }
  else if(element_number>s->top){
        printf("Not a valid Position\n");
        return -1;
    }
    else{
        int element=s->arr[element-1];
        return element;
    }
}

void pop(struct Stack *s){
    int val=s->arr[s->top];
    s->top--;
    printf("Removed element is %d\n",val);
}

int stackTop(struct Stack *s){
    return s->arr[s->top];
}

int stackBottom(struct Stack *s){
    return s->arr[0];
}


int main(){
  
   struct Stack *s = malloc(sizeof(struct Stack)); // Allocate memory for the struct
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error
    }

    s->size = 80;
    s->top = -1;  //show the stack is Empty
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

    // TO peek our element at number 3
    int top=peek(s,3);
    printf("Peeked element is %d\n",top);


// TO pop element from stack
    pop(s);
    pop(s);

    // Display our stack
    Display(s);

// TO display TOP
    top=peek(s,s->top);
    printf("Top element is %d\n",top);


// Stack Top 
int Top=stackTop(s);
    printf("Stack Top is %d\n",Top);

// STtack Bottom 
int Bottom=stackBottom(s);
    printf("Stack Bottom is %d\n",Bottom);


return 0;
}