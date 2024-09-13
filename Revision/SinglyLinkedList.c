#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Function to calculate the length of the linked list
int lenNode(node *n1){
    node *temp = n1;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// Function to create a new node
node* createnode() {
    node *temp = (node *)malloc(sizeof(node)); 
    int x;
    printf("Enter the data you want in your node\n");
    scanf("%d", &x);
    temp->data = x;
    temp->next = NULL;
    return temp; 
}

// Function to display the linked list
void display(node *n1) {
    if(n1 == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = n1;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to insert a node at the beginning
node *InsertionBeginning(node *n1){
    node *temp = createnode();
    temp->next = n1;
    return temp;
}

// Function to insert a node at the end
node *InsertionEnd(node *n1){
    node *temp = createnode();
    if(n1 == NULL) {
        return temp;
    }
    
    node *ptr = n1;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return n1;
}

// Function to insert a node at a specific index
node *InsertionAtIndex(node *n1){
    int index;
    printf("Enter index to insert\n");
    scanf("%d", &index);

    if(index > lenNode(n1) || index < 0){
        printf("Invalid index\n");
        return n1;
    }

    if(index == 0){
        return InsertionBeginning(n1);
    }

    node *temp = createnode();
    node *ptr = n1;

    for(int i = 0; i < index - 1; i++){
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return n1;
}

// Manage insertion operations
node *Insertion(node *n1){
    while (true)
    {
        int choice;
        printf("\n\nWhat do you want to do?\n1-Insertion At Beginning\n2-Insertion At End\n3-Insertion At Specific Index\n4-Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            n1 = InsertionBeginning(n1); 
            break;
        case 2:
            n1 = InsertionEnd(n1);
            break;
        case 3:
            n1 = InsertionAtIndex(n1);
            break;
        case 4:
            return n1;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

// Function to delete a node at the beginning
node *deletionBeginning(node *n1){
    if(n1 == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node *temp = n1;
    n1 = temp->next;
    free(temp);
    return n1;
}

// Function to delete a node at the end
node *deletionEnd(node *n1){
    if(n1 == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if(n1->next == NULL) {
        free(n1);
        return NULL;
    }

    node *temp = n1;
    node *prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    return n1;
}

// Function to delete a node at a specific index
node *deletionIndex(node *n1){
    int index;
    printf("Enter index to delete\n");
    scanf("%d", &index);

    if(index >= lenNode(n1) || index < 0){
        printf("Invalid index\n");
        return n1;
    }

    if(index == 0){
        return deletionBeginning(n1);
    }

    node *prev = n1;
    for(int i = 0; i < index - 1; i++){
        prev = prev->next;
    }

    node *curr = prev->next;
    prev->next = curr->next;
    free(curr);
    return n1;
}

// Manage deletion operations
node *deletion(node *n1){
    while (true)
    {
        int choice;
        printf("\n\nWhat do you want to do?\n1-Deletion At Beginning\n2-Deletion At End\n3-Deletion At Specific Index\n4-Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            n1 = deletionBeginning(n1); 
            break;
        case 2:
            n1 = deletionEnd(n1);
            break;
        case 3:
            n1 = deletionIndex(n1);
            break;
        case 4:
            return n1;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

// Function to search for an element in the linked list
void searching(node *n1, int ele){
    node *temp = n1;
    int i = 0;
    bool flag = false;

    while(temp != NULL){
        if(temp->data == ele){
            printf("Element found at index %d\n", i);
            flag = true;
        }
        temp = temp->next;
        i++;
    }

    if(!flag){
        printf("Element not found\n");
    }
}

int main() {
    node *n1 = NULL; 
    int choice;

    while (true)
    {
        printf("\nEnter your choice\n1-Insertion\n2-Deletion\n3-Display\n4-Searching\n5-Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n1 = Insertion(n1);
                break;
            case 2:
                n1 = deletion(n1);
                break;
            case 3:
                display(n1);
                break;
            case 4: {
                int search_ele;
                printf("Enter data to search\n");
                scanf("%d", &search_ele);
                searching(n1, search_ele);
                break;
            }
            case 5:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
}


