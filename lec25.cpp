/*
 * ======================================================================================
 * Problem: Check for Symmetric Binary Tree
 * Lecture: Lecture 25
 * Reference: LeetCode 101 - Symmetric Tree
 * 
 * Description:
 * Check whether a binary tree is a mirror image of itself (symmetric around its center).
 * 
 * Intuition & Approach:
 * Compare left and right subtrees simultaneously. Left node must equal right node, left subtree of left child must match right subtree of right child, and right subtree of left child must match left subtree of right child.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursive stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 100 - Same Tree
 *   2. LeetCode 226 - Invert Binary Tree
 *   3. LeetCode 572 - Subtree of Another Tree
 * ======================================================================================
 */

// //check for symmetric tree
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
//     bool isSymmetric(TreeNode* root) {
//         return root == nullptr || isSymmetricHelp(root->left, root->right);
//     }

//     bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
//         if (left == nullptr || right == nullptr) {
//             return left == right;
//         }
//         if (left->val != right->val) {
//             return false;
//         }
//         return isSymmetricHelp(left->left, right->right) && 
//                isSymmetricHelp(left->right, right->left);
//     }


// int main(){
//     TreeNode* root=new TreeNode(1);
//     root->left=new TreeNode(2);
//     root->right=new TreeNode(2);
//     root->left->left=new TreeNode(3);
//     root->left->right=new TreeNode(4);
//     root->right->left=new TreeNode(4);
//     root->right->right=new TreeNode(3);
//     if(isSymmetric(root)){
//         cout<<"The tree is symmetric"<<endl;
//     } else {
//         cout<<"The tree is not symmetric"<<endl;
//     }
//     return 0;
// }