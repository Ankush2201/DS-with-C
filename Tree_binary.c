#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int val) {
    if (node == NULL)
        return newNode(val);

    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);

    return node;
}

void preorderTraversal(struct node *root_node) {
    if (root_node != NULL) {
        printf("%d\t", root_node->data);
        preorderTraversal(root_node->left);
        preorderTraversal(root_node->right);
    }
}

void inorderTraversal(struct node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d\t", node->data);
        inorderTraversal(node->right);
    }
}

void postorderTraversal(struct node *node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("\t%d", node->data);
    }
}

int height(struct node *node) {
    if (node == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int countNodes(struct node *node) {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
}

void displayMenu() {
    printf("\n===== Binary Search Tree Menu =====\n");
    printf("1. Insert Element\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("7. Exit\n");
    printf("6. Height of the BST\n");
    printf("5. Total Node Count\n");
    printf("===================================\n");
}

int main() {
    struct node *root = NULL;
    int choice, val;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter -1 to Exit the insertion --");
                    printf("Enter Element :\n");
                    scanf("%d", &val);
                    if (val != -1) {
                        root = insert(root, val);
                    }
                } while (val != -1);
                printf("Element inserted successfully!\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;

            case 6:
                printf("Height of the BST: %d\n", height(root));
                break;

            case 5:
                printf("Total Node Count: %d\n", countNodes(root));
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
