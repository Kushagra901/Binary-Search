/*
 * ======================================================================================
 * Problem: Check for Balanced Binary Tree
 * Lecture: Lecture 15
 * Reference: LeetCode 110 - Balanced Binary Tree
 * 
 * Description:
 * Determine if a binary tree is height-balanced (for every node, abs(height(left) - height(right)) <= 1).
 * 
 * Intuition & Approach:
 * Compute height bottom-up. If any subtree is unbalanced (diff > 1), return -1 immediately to prune unnecessary recursion. If both subtrees are balanced, return actual height `1 + max(lh, rh)`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) (avoids O(N^2) naive check) | Space Complexity: O(H)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 104 - Maximum Depth of Binary Tree
 *   2. LeetCode 111 - Minimum Depth of Binary Tree
 *   3. GFG - Check for Balanced Tree
 * ======================================================================================
 */

//check balance binary tree
#include <bits/stdc++.h>
using namespace std;

//recursive approach
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x){
//         val=x;
//         left=NULL;
//         right=NULL; 
//     }
// };

// int maxDepth(TreeNode* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int leftHeight = maxDepth(root->left);
//     int rightHeight = maxDepth(root->right);
//     return max(leftHeight, rightHeight) + 1;
// }

// bool checkBalance(TreeNode* root){
//     if(root==NULL){
//         return true;
//     }
//     int leftHeight=maxDepth(root->left);
//     int rightHeight=maxDepth(root->right);
//     if(abs(leftHeight-rightHeight)>1){
//         return false;
//     }
//     bool left = checkBalance(root->left);
//     bool right = checkBalance(root->right);
//     if(left || right){
//         return false;
//     }
//     return true;
// }
    
//optimise
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
// bool isBalanced(TreeNode* root){
//     return dfsHeight(root) != -1;
// } 
// int dfsHeight(TreeNode* root){
//     if(root==NULL){
//         return 0;
//     } else {
//         int leftHeight=dfsHeight(root->left);
//         if(leftHeight==-1){
//             return -1;
//         }
//         int rightHeight=dfsHeight(root->right);
//         if(rightHeight==-1){
//             return -1;
//         }
//         if(abs(leftHeight-rightHeight)>1){
//             return -1;
//         }
//         return max(leftHeight, rightHeight) + 1;
//     }
// }
// int main(){
//     // Create a simple binary tree
//     //       3
//     //      / \
//     //     9   20
//     //        /  \
//     //       15   7
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);

//     if(balancedBTree(root) == -1){
//         cout << "The tree is not balanced." << endl;
//     } else {
//         cout << "The tree is balanced." << endl;
//     }

//     return 0;
// }