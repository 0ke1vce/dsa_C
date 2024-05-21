#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    char *arr;
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



void pop(struct Stack *s){
    int val=s->arr[s->top];
    s->top--;
}

int parenthesisMatch(char *exp){
    struct Stack *sp = malloc(sizeof(struct Stack));
    if(sp == NULL){
        printf("Memory allocation failed\n");
        return 0; // Indicate failure
    }
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    if(sp->arr == NULL){
        printf("Memory allocation failed\n");
        free(sp);
        return 0; // Indicate failure
    }
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(sp, exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                free(sp->arr);
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        free(sp->arr);
        free(sp);
        return 1;
    }
    else{
        free(sp->arr);
        free(sp);
        return 0;
    }
}

int main(){
  
   struct Stack *s = malloc(sizeof(struct Stack)); // Allocate memory for the struct
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error
    }

    s->size = 80;
    s->top = -1;  //show the stack is Empty
    s->arr = (char *)malloc(s->size * sizeof(int));

    char *exp="2*(3-(8+1)";
    if(parenthesisMatch(exp)){
        printf("balanced\n");
    }
    else{
        printf("Unbalanced\n");
    }
    
  


return 0;
}