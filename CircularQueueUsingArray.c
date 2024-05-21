#include<stdio.h>
#include<stdlib.h>

struct Cqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Cqueue *q){
    if(q->r==q->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Cqueue *q){
    if(((q->r+1)%q->size)==q->f){     // agar circular increment kiya q ka or vo front m agya h to circular queue is full.
        return 1;
    }
    else{
        return -1;
    }
}


void enqueue(struct Cqueue *q,int val){
    if(isFull(q)){
        printf("This Cqueue is Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;   //circular increment kiya
        q->arr[q->r] = val;
    }
}

void dequeue(struct Cqueue *q){
    int val=-1;
    if(q->r==q->r){
        printf("Empty queue\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
    }
}

int main(){
    struct Cqueue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));


    // Enqueue some elements.
    enqueue(&q,5);
    enqueue(&q,51);
    enqueue(&q,15);
    
//  Dequeue some element 
     dequeue(&q);
   
    

 return 0;   
}