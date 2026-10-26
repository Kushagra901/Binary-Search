/*
 * ======================================================================================
 * Problem: Validate Binary Search Tree / Check if Tree is BST
 * Lecture: Lecture 46
 * Reference: LeetCode 98 - Validate Binary Search Tree
 * 
 * Description:
 * Determine if a given binary tree is a valid Binary Search Tree (strictly BST).
 * 
 * Intuition & Approach:
 * Every node must lie in a valid range `(minVal, maxVal)`. Root has range `(-INF, +INF)`. When going left, update `maxVal = node->val`. When going right, update `minVal = node->val`. If node fails range, return false.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 99 - Recover Binary Search Tree
 *   2. LeetCode 230 - Kth Smallest Element in a BST
 *   3. GFG - Check for BST
 * ======================================================================================
 */

//check if a tree is bst or not
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal){
    if(root == NULL){
        return true;
    }
    if(root->data <= minVal || root->data >= maxVal){
        return false;
    }
    return isValidBSTHelper(root->left, minVal, root->data) && isValidBSTHelper(root->right, root->data, maxVal);
}
bool isValidBST(TreeNode* root){
    return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;
    return 0;
}