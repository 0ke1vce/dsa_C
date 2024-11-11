/*

Deque (Double-Ended Queue) Overview
A Deque (Double-Ended Queue) is a data structure that allows insertion and deletion of elements at both the front and rear ends. This makes it more flexible than a regular queue or stack, as it can behave like both.

Basic Operations & Time Complexity-
Operation	                                 Description	                                         Time Complexity
push_front()	                             Insert element at the beginning	                         O(1)
push_back()	                                 Insert element at the end                                   O(1)
pop_front()	                                 Remove element from the front	                             O(1)
pop_back()	                                 Remove element from the rear	                             O(1)
front()	                                     Get the front element	                                     O(1)
back()	                                     Get the rear element	                                     O(1)
empty()	                                     Check if the deque is empty	                             O(1)
size()	                                     Get the number of elements in the deque	                 O(1)


Additional Operations-
1-clear(): Removes all elements, leaving the deque empty.
2-erase(): Removes a specific range of elements.
3-swap(): Swaps contents between two deques.
4-emplace_front() / emplace_back(): Efficiently inserts elements at the front or back, avoiding unnecessary copying.
5-resize(): Adjusts the number of elements by either adding or removing elements.
6-assign(): Replaces the current contents with new values.
7-reverse(): Reverses the order of elements in the deque.
8-sort(): Sorts the elements in ascending order.




Applications of Deque
1-As Stack and Queue: Since deque supports both front and rear operations, it can be used to implement both stacks and queues.
2-Web Browser History: Deques can store a browser’s history, allowing navigation forward and backward.
3-Undo Operations: Deques efficiently track undo/redo actions in software by pushing and popping states from both ends.
4-Job Scheduling: Deques can be used for task management in scheduling algorithms.


#Monotonic Deque-
A Monotonic Deque stores elements in either strictly increasing or strictly decreasing order. For example, in a decreasing deque, if an element is inserted that breaks the order, smaller elements are removed from the deque until order is restored.
This is useful in: Sliding Window Problems: Maintaining the max or min in a subarray.



Other Practical Applications
1-Palindrome Checking: By comparing characters from both ends, a deque can determine if a string is a palindrome.
2-Graph Traversal: Deques can be used to implement Breadth-First Search (BFS), an alternative to a queue.
3-Task Scheduler: Tasks can be added to the back and executed from the front of the deque.
4-Multi-level Undo/Redo: Deques can track application states for undo and redo functionality.
5-Algorithms: Deques are used in algorithms like Least Recently Used (LRU) Cache, Round Robin Scheduling, and expression evaluation.

Conclusion-
            Deques are highly versatile structures due to their support for insertions and deletions at both ends, making them useful for a variety of applications including browser history, undo functionality, scheduling tasks, and more complex algorithms.

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int rear, front, capacity;
    int *arr;
} queue;
    
queue *createqueue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int)); // Allocate correct memory for 'size' elements
    return q;
}

int isFull(queue *q) {
    return q->rear == q->capacity - 1;
}

int isEmpty(queue *q) {
    return q->rear < q->front;
}

int size(queue *q) {
    return q->rear - q->front + 1;
}

int frontqueue(queue *q) {
    if (!isEmpty(q)) return q->arr[q->front];
    printf("Queue is empty\n");
    return -1;
}

int rearqueue(queue *q) {
    if (!isEmpty(q)) return q->arr[q->rear];
    printf("Queue is empty\n");
    return -1;
}

void pushfront(queue *q, int val) {
    if (isFull(q)) {
        printf("Cannot push, queue is full\n");
        return;
    }

    // Shift all elements to the right to make space at the front
    for (int i = q->rear; i >= q->front; i--) {
        q->arr[i + 1] = q->arr[i];
    }

    // Insert the new value at the front
    q->arr[q->front] = val;

    // Update the rear to reflect the new element added
    q->rear++;
}

void pushrear(queue *q, int val) {
    if (isFull(q)) {
        printf("Cannot push, queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d<-", q->arr[i]);
    }
    printf("\n");
}

void poprear(queue *q) {
    if (isEmpty(q)) {
        printf("Underflow - Queue is empty\n");
        return;
    }
    q->rear--;
}

void popfront(queue *q) {
    if (isEmpty(q)) {
        printf("Underflow - Queue is empty\n");
        return;
    }

    // Print the element being removed
    printf("Popped element: %d\n", q->arr[q->front]);

    // Increment the front to effectively remove the front element
    q->front++;

    // If the front surpasses the rear, reset both to indicate an empty queue
    if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }
}

int main() {
    queue *q = createqueue(10);

    // Test pushing to the front
    pushfront(q, 32);
    pushfront(q, 33);
    pushfront(q, 37);
    pushfront(q, 34);
    
    // Test popping from the front
    popfront(q);
    display(q);

    // Test pushing to the rear
    pushrear(q, 72);
    pushrear(q, 75);
    pushrear(q, 74);
    pushrear(q, 71);
    
    // Test popping from the rear
    poprear(q);
    display(q);

    printf("Size of Queue is %d\n", size(q));

    return 0;
}
