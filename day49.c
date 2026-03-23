#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Driver code
int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 7);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}