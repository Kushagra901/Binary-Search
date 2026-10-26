/*
 * ======================================================================================
 * Problem: Search in a Binary Search Tree
 * Lecture: Lecture 40
 * Reference: LeetCode 700 - Search in a Binary Search Tree
 * 
 * Description:
 * Find the node in the BST that the node's value equals val and return the subtree rooted with that node.
 * 
 * Intuition & Approach:
 * Binary search logic: if `val == root->val`, return root. If `val < root->val`, search left subtree `root = root->left`. If `val > root->val`, search right subtree `root = root->right`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) where H is tree height (O(log N) balanced, O(N) worst) | Space Complexity: O(1) iterative
 * 
 * Similar / Related Problems:
 *   1. LeetCode 701 - Insert into a Binary Search Tree
 *   2. LeetCode 450 - Delete Node in a BST
 *   3. LeetCode 270 - Closest Binary Search Tree Value
 * ======================================================================================
 */

//search in a binary search tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL; 
    }
};
TreeNode* searchBST(TreeNode* root, int val){
    while(root!=NULL && root->data!=val){
        root = val < root->data ? root->left : root->right;

    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode* result = searchBST(root, 5);
    if(result){
        cout << "Found: " << result->data << endl;
    }else{
        cout << "Not found" << endl;
    }

    return 0;
}