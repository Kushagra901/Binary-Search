/*
 * ======================================================================================
 * Problem: Diameter of Binary Tree
 * Lecture: Lecture 16
 * Reference: LeetCode 543 - Diameter of Binary Tree
 * 
 * Description:
 * Find the length of the longest path between any two nodes in a binary tree. This path may or may not pass through the root.
 * 
 * Intuition & Approach:
 * At every node, the longest path passing through it is `lh + rh`. Compute the height of left and right subtrees recursively, update `diameter = max(diameter, lh + rh)`, and return `1 + max(lh, rh)`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 124 - Binary Tree Maximum Path Sum
 *   2. LeetCode 687 - Longest Univalue Path
 *   3. LeetCode 1522 - Diameter of N-Ary Tree
 * ======================================================================================
 */

//diameter in binary tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL; 
    }
};
//brute force
// int findHeight(TreeNode* root){
//     if(root==NULL){
//         return 0;
//     }
//     int leftHeight=findHeight(root->left);
//     int rightHeight=findHeight(root->right);
//     return 1 + max(leftHeight,rightHeight)+1;
// }
// int findDiameter(TreeNode* root){
//     if(root==NULL){
//         return 0;
//     }
//     int leftHeight=findHeight(root->left);
//     int rightHeight=findHeight(root->right);
//     int currentDiameter=leftHeight+rightHeight;
//     int leftDiameter=findDiameter(root->left);
//     int rightDiameter=findDiameter(root->right);
//     return max(currentDiameter,max(leftDiameter,rightDiameter));
// }
// int diameterOfBinaryTree(TreeNode* root) {
//     return findDiameter(root);
// }
//optimal
int height(TreeNode* node, int& diameter) {
    if (!node) {
        return 0;
    }
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<diameterOfBinaryTree(root)<<endl;
    return 0;
}