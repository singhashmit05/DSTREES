#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to find the largest element in the BST
int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Indicating the tree is empty
    }
    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->key;
}

// Function to find the smallest element in the BST
int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Indicating the tree is empty
    }
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

// Function to calculate the height of a node with a given key
int height(struct Node* root, int key) {
    if (root == NULL) {
        return -1; // Node not found
    }
    if (root->key == key) {
        return calculateHeight(root);
    }
    if (key < root->key) {
        return height(root->left, key);
    } else {
        return height(root->right, key);
    }
}

// Helper function to calculate the height of a node
int calculateHeight(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count the number of leaf nodes in the BST
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function to drive the program
int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element to the BST\n");
        printf("2. Display the largest element\n");
        printf("3. Display the smallest element\n");
        printf("4. Height of a node\n");
        printf("5. Count number of leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d into the BST.\n", key);
                break;

            case 2:
                key = findLargest(root);
                if (key != -1) {
                    printf("Largest element in the BST: %d\n", key);
                }
                break;

            case 3:
                key = findSmallest(root);
                if (key != -1) {
                    printf("Smallest element in the BST: %d\n", key);
                }
                break;

            case 4:
                printf("Enter the node to find its height: ");
                scanf("%d", &key);
                int h = height(root, key);
                if (h >= 0) {
                    printf("Height of node %d: %d\n", key );
                }
        }
    }
}
