/*
 * ======================================================================================
 * Problem: Inorder Traversal of Binary Tree (Recursive)
 * Lecture: Lecture 6
 * Reference: LeetCode 94 - Binary Tree Inorder Traversal
 * 
 * Description:
 * Traverse a binary tree in inorder sequence: Left Subtree -> Root -> Right Subtree recursively. For BST, this yields nodes in strictly sorted order.
 * 
 * Intuition & Approach:
 * Recursively visit the left subtree until reaching NULL, process the current node's value, and then recursively traverse the right subtree.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 144 - Binary Tree Preorder Traversal
 *   2. LeetCode 145 - Binary Tree Postorder Traversal
 *   3. LeetCode 230 - Kth Smallest Element in a BST
 * ======================================================================================
 */

//inorder traversal of binary tree
// #include <bits/stdc++.h>
// using namespace std;

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
// void inorder(struct TreeNode* root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }




//   vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorderHelper(root, result);
//         return result;
//     }

//     void inorderHelper(TreeNode* root, vector<int>& result) {
//         if (root == NULL) {
//             return;
//         }
//         inorderHelper(root->left, result);
//         result.push_back(root->val);
//         inorderHelper(root->right, result);
//     }

// int main(){
//     struct TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     inorder(root);

// }