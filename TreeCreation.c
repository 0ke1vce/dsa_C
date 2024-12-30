#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes
#define MAX_NODES 100

// Adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX_NODES]; // Array of adjacency lists

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between vertices x and y
void addEdge(int x, int y) {
    Node* newNode = createNode(y);
    newNode->next = adj[x];
    adj[x] = newNode;

    newNode = createNode(x);
    newNode->next = adj[y];
    adj[y] = newNode;
}

// Function to print the parents of each node (DFS)
void printParents(int node, int parent, int visited[]) {
    visited[node] = 1;

    if (parent == 0)
        printf("%d -> Root\n", node);
    else
        printf("%d -> %d\n", node, parent);

    Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->vertex]) {
            printParents(temp->vertex, node, visited);
        }
        temp = temp->next;
    }
}

// Function to print the children of each node (BFS)
void printChildren(int root) {
    int queue[MAX_NODES], front = 0, rear = 0;
    int visited[MAX_NODES] = {0};

    queue[rear++] = root;
    visited[root] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d -> ", node);

        Node* temp = adj[node];
        while (temp) {
            if (!visited[temp->vertex]) {
                printf("%d ", temp->vertex);
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to print the leaf nodes
void printLeafNodes(int root) {
    for (int i = 1; i < MAX_NODES; i++) {
        if (i != root) {
            Node* temp = adj[i];
            int degree = 0;

            while (temp) {
                degree++;
                temp = temp->next;
            }

            if (degree == 1) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

// Function to print the degrees of each node
void printDegrees(int root) {
    for (int i = 1; i < MAX_NODES; i++) {
        Node* temp = adj[i];
        int degree = 0;

        while (temp) {
            degree++;
            temp = temp->next;
        }

        if (i == root)
            printf("%d: %d\n", i, degree);
        else
            printf("%d: %d\n", i, degree > 0 ? degree - 1 : 0);
    }
}

// Driver code
int main() {
    int N = 7, Root = 1;

    // Initialize adjacency list
    for (int i = 0; i < MAX_NODES; i++) {
        adj[i] = NULL;
    }

    // Create the tree
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(4, 7);

    // Print parents of each node
    printf("The parents of each node are:\n");
    int visited[MAX_NODES] = {0};
    printParents(Root, 0, visited);

    // Print children of each node
    printf("The children of each node are:\n");
    printChildren(Root);

    // Print the leaf nodes
    printf("The leaf nodes of the tree are:\n");
    printLeafNodes(Root);

    // Print the degrees of each node
    printf("The degrees of each node are:\n");
    printDegrees(Root);

    return 0;
}
