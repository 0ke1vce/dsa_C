#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node iteratively
void insert(struct Node** root, int key) {
    struct Node* p = *root;
    struct Node* prev = NULL;

    // If the tree is empty
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    // Traverse to find the correct position
    while (p != NULL) {
        prev = p;
        if (key < p->data) {
            p = p->left;
        } else if (key > p->data) {
            p = p->right;
        } else {
            return; // Key already exists
        }
    }

    // Insert the new node
    if (key < prev->data) {
        prev->left = createNode(key);
    } else {
        prev->right = createNode(key);
    }
}

// Function for inorder traversal
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search a node iteratively
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL; // Key not found
}

// Function to find the height of the tree
int height(struct Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find the inorder predecessor
struct Node* inPre(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find the inorder successor
struct Node* inSucc(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node
struct Node* delete(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = inSucc(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 8);
    insert(&root, 30);

    // Inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // Search for a node
    struct Node* found = search(root, 8);
    if (found) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Element not found\n");
    }

    // Height of the tree
    printf("Height of tree: %d\n", height(root));

    // Delete a node
    root = delete(root, 10);
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
