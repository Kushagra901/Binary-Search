/*
 * ======================================================================================
 * Problem: Count Total Nodes in a Complete Binary Tree
 * Lecture: Lecture 32
 * Reference: LeetCode 222 - Count Complete Tree Nodes
 * 
 * Description:
 * Count the number of nodes in a complete binary tree in less than O(N) time.
 * 
 * Intuition & Approach:
 * Exploit complete binary tree property: Find leftmost height `lh` and rightmost height `rh`. If `lh == rh`, tree is full; node count is `(1 << lh) - 1`. If not equal, recursively count `1 + countNodes(left) + countNodes(right)`. Only one sub-branch is not full at each step.
 * 
 * Complexity Analysis:
 * - Time Complexity: O((log N)^2) | Space Complexity: O(log N) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 104 - Maximum Depth of Binary Tree
 *   2. LeetCode 226 - Invert Binary Tree
 *   3. GFG - Complete Binary Tree
 * ======================================================================================
 */

//count the number of node in a complete binary tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh==rh) return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);

}
int findHeightLeft(TreeNode* root){
    int h=0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int findHeightRight(TreeNode* root){
    int h=0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << countNodes(root) << endl;
    return 0;
}