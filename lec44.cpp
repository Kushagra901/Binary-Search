/*
 * ======================================================================================
 * Problem: Delete a Node in a Binary Search Tree
 * Lecture: Lecture 44
 * Reference: LeetCode 450 - Delete Node in a BST
 * 
 * Description:
 * Delete a node with given key in a BST and return the root. Maintain BST property after deletion.
 * 
 * Intuition & Approach:
 * Search for node. When found: If node has 0 children, return NULL. If 1 child, return non-null child. If 2 children, find rightmost child of left subtree (or leftmost of right subtree) and attach right subtree to it, then return left subtree.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) | Space Complexity: O(H) recursive or O(1) iterative
 * 
 * Similar / Related Problems:
 *   1. LeetCode 701 - Insert into a BST
 *   2. LeetCode 700 - Search in a BST
 *   3. LeetCode 669 - Trim a Binary Search Tree
 * ======================================================================================
 */

//delete a node in binary search tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};  
TreeNode* deleteNode(TreeNode* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return helper(root);
    }
    TreeNode* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }else{
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
    }
    return dummy;
}
TreeNode* helper(TreeNode* root){
    if(root->left == NULL){
        return root->right;
    }else if(root->right == NULL){
        return root->left;
    }
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode* findLastRight(TreeNode* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}


int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    int keyToDelete = 6;
    root = findMin(root, keyToDelete);

    // Print the tree in-order to verify deletion
    function<void(TreeNode*)> inOrderTraversal = [&](TreeNode* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    };

    cout << "In-order traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}