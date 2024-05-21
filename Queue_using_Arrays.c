#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
     if(q->r==q->size-1){
        return 1;
     }
     else{
        return 0;
     }
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}


int main(){
        struct queue q;
        q.size=100;
        q.f=q.r=-1;
        q.arr=(int *)malloc(q.size*sizeof(int));

        if(isEmpty(&q)){
            printf("Queue is empty now\n");
        }

        enqueue(&q,54);
        enqueue(&q,12);

        if(isEmpty(&q)){
            printf("Queue is empty now!\n");
        }
        else{
            printf("queue is not empty now\n");
        }

        dequeue(&q);
        dequeue(&q);

        if(isEmpty(&q)){
            printf("Queue is empty now!\n");
        }
        else{
            printf("queue is not empty now\n");
        }

}


