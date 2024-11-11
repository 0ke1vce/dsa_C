#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int rear, front, capacity;
    int* arr;
} queue;

// Function to create a queue
queue* createqueue(int size) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = size;
    q->rear = -1;
    q->front = 0;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q; // Fix: Return the created queue
}

// Function to display the queue
void display(queue* q) {
    if (q->rear < q->front) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Function to enqueue an element
void enqueue(queue* q, int val) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full cannot enqueue\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

// Function to dequeue an element
int dequeue(queue* q) {
    if (q->rear < q->front) {
        return -1;
    }
    int x = q->arr[q->front]; // Fix: Return the value at front, not the index
    q->front++;               // Increment the front
    return x;
}

// Function to peek the front element
int peek(queue* q) {
    if (q->rear < q->front) {
        return -1; // Queue is empty
    }
    return q->arr[q->front];
}

// Function to check if the queue is empty
void Empty(queue* q) {
    if (q->rear < q->front) {
        printf("Queue is Empty\n");
    } else {
        printf("Not empty\n");
    }
}

// Function to check if the queue is full
void isFull(queue* q) {
    if (q->rear == q->capacity - 1) { // Fix: Check if rear equals capacity - 1
        printf("Queue is Full\n");
    } else {
        printf("Not full\n");
    }
}

int rear(queue *q){
    if(q->rear==-1){
        return -1;
    }
    return q->arr[q->rear];
}

int main() {
    queue* queue;

    // Fix: initialize queue correctly
    queue = createqueue(10);

    // Test with displaying an empty queue
    display(queue);

    // Enqueue elements
    enqueue(queue, 1);
    enqueue(queue, 13);
    enqueue(queue, 7);
    enqueue(queue, 5);
    enqueue(queue, 4);

    // Display the queue
    printf("Queue after enqueuing:\n");
    display(queue);

    // Dequeue an element
    int x = dequeue(queue);
    if (x == -1) {
        printf("Queue is empty cannot dequeue\n");
    } else {
        printf("Deleted element is %d\n", x);
    }

    // Display the queue again
    printf("Queue after dequeuing:\n");
    display(queue);

    // Peek the front element
    int peek_queue = peek(queue);
    if (peek_queue == -1) {
        printf("Queue is empty, no front element\n");
    } else {
        printf("Peeked element is %d\n", peek_queue);
    }

// return the rear element
    int rearqueue=rear(queue);
    if (rearqueue == -1) {
        printf("Empty\n");
    }
    else{
        printf("Rear element is %d\n",rearqueue);
    }

    return 0;
}


/*

Basic Operations for Queue in Data Structure

enqueue() – Inserts an element at the rear end of the queue:
            Check if the queue is full; if so, return an overflow error.
            If not full, increment the rear pointer and add the element to the queue.

dequeue() – Removes the element from the front of the queue:
            Check if the queue is empty; if so, return an underflow error.
            If not empty, access the front element and increment the front pointer.

front() – Returns the element at the front of the queue without removing it:
    If the queue is empty, return the minimum value, otherwise return the front element.

rear() – Returns the element at the rear of the queue without removing it:
        If the queue is empty, return the minimum value, otherwise return the rear element.

isEmpty() – Checks if the queue is empty:
Returns true if the size is 0, indicating the queue is empty.

isFull() – Checks if the queue is full:
Returns true if the size is equal to the capacity of the queue.

size() – Returns the total number of elements in the queue.

Complexity Analysis:
    Time Complexity: All operations have O(1) time complexity.
    Space Complexity: O(N), where N is the capacity of the queue

*/