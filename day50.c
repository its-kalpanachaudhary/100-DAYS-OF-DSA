#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }

    if (key < root->val) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}