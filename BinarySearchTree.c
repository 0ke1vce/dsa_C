#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void search(node *root, int key) {
    if (root == NULL) {
        printf("Empty BST\n");
        return;
    }
    node *t = root;
    while (t != NULL) {
        if (key == t->data) {
            printf("Data %d found\n", key);
            return;
        } else if (key < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
    printf("Data %d not found\n", key);
}

void RecursiveSearch(node *root, int key) {
    if (root == NULL) {
        printf("Data %d not found\n", key);
        return;
    }
    if (key == root->data) {
        printf("Data %d found\n", key);
        return;
    } else if (key < root->data) {
        RecursiveSearch(root->left, key);
    } else {
        RecursiveSearch(root->right, key);
    }
}

node *Insert(node *root, int key) {
    if (root == NULL) {
        return createnode(key);
    }
    node *t = root;
    node *r = NULL;

    while (t != NULL) {
        r = t;
        if (key == t->data) {
            printf("Key already exists\n");
            return root;
        } else if (key < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }

    node *p = createnode(key);
    if (key < r->data) {
        r->left = p; // Corrected: Assign to left if key is smaller
    } else {
        r->right = p; // Assign to right if key is larger
    }
    return root;
}

node *RecursionInsert(node *root, int key) {
    if (root == NULL) {
        return createnode(key);
    }
    if (key < root->data) {
        root->left = RecursionInsert(root->left, key);
    } else if (key > root->data) {
        root->right = RecursionInsert(root->right, key);
    } else {
        printf("Key already exists\n");
    }
    return root;
}

void inorder(node *root) {
    if (root == NULL) {
        return; // If the root is NULL, simply return.
    }
    inorder(root->left);           // Traverse the left subtree
    printf("%d ", root->data);     // Visit the root node
    inorder(root->right);          // Traverse the right subtree
}

int main() {
    node *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 100);
    root = Insert(root, 20);
    root = Insert(root, 360);
    root = Insert(root, 560);
    root = Insert(root, 50); // Duplicate key, should print "Key already exists"
    root = Insert(root, 10);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("\nIterative Search Results:\n");
    search(root, 50);
    search(root, 100);
    search(root, 123);

    printf("\nRecursive Search Results:\n");
    RecursiveSearch(root, 50);
    RecursiveSearch(root, 100);
    RecursiveSearch(root, 123);

    return 0;
}
