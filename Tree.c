#include<stdio.h>
#include<stdlib.h>

// Define the structure of the tree node
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

// Function to create a new node
node *createNode(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Inorder Traversal (Left, Root, Right):
void inorderTraversal(node *root){
    if (root == NULL)
        return;
    inorderTraversal(root->left);  // Visit left subtree
    printf("%d ", root->data);     // Visit root
    inorderTraversal(root->right); // Visit right subtree
}

// Preorder Traversal (Root, Left, Right):
void preorderTraversal(node *root){
    if(root == NULL)
        return;
    printf("%d ", root->data);     // Visit root
    preorderTraversal(root->left); // Visit left subtree
    preorderTraversal(root->right);// Visit right subtree
}

// Postorder Traversal (Left, Right, Root):
void postorderTraversal(node *root){
    if(root == NULL)
        return;
    postorderTraversal(root->left);  // Visit left subtree
    postorderTraversal(root->right); // Visit right subtree
    printf("%d ", root->data);       // Visit root
}

int main() {
    // Creating the root node
    node* root = createNode(1);

    // Creating child nodes
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Traversals
    printf("Inorder Traversal: ");
    inorderTraversal(root);  // Output: 4 2 5 1 6 3 7
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);  // Output: 1 2 4 5 3 6 7
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);  // Output: 4 5 2 6 7 3 1
    printf("\n");

    return 0;
}


/*

Explanation:
Node Structure (node): Each node in the tree contains:

data: Integer value.
left: Pointer to the left child.
right: Pointer to the right child.
Traversal Functions:

Inorder Traversal: Left subtree → Root → Right subtree.
Preorder Traversal: Root → Left subtree → Right subtree.
Postorder Traversal: Left subtree → Right subtree → Root.
Tree Creation:

A root node (1) is created with two children (2 and 3).
Further, each of these children has their own children (4, 5, 6, 7), forming a complete binary tree.
Traversals:

The three traversal functions are called, and they print the nodes in their respective orders.


*/