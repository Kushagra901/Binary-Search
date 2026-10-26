/*
 * ======================================================================================
 * Problem: Postorder Traversal of Binary Tree (Recursive)
 * Lecture: Lecture 7
 * Reference: LeetCode 145 - Binary Tree Postorder Traversal
 * 
 * Description:
 * Traverse a binary tree in postorder sequence: Left Subtree -> Right Subtree -> Root recursively.
 * 
 * Intuition & Approach:
 * Process all descendants of a node before processing the node itself. Used commonly for bottom-up evaluations like deleting a tree or calculating height/diameter.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 94 - Binary Tree Inorder Traversal
 *   2. LeetCode 590 - N-ary Tree Postorder Traversal
 *   3. LeetCode 110 - Balanced Binary Tree
 * ======================================================================================
 */

// post order traversal of a binary tree
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
// void postorder(struct TreeNode* root){
//     if(root==NULL){
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->val << " ";
// }
// vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> result;
//     postorderTraversalHelper(root, result);
//     return result;     
//     }
// void postorderTraversalHelper(TreeNode* root, vector<int>& result) {
//         if (root == NULL) {
//             return;
//         }
//         postorderTraversalHelper(root->left, result);
//         postorderTraversalHelper(root->right, result);
//         result.push_back(root->val);
//     }
// int main(){
//     struct TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     postorder(root);

// }