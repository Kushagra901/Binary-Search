/*
 * ======================================================================================
 * Problem: Construct BST from Preorder Traversal
 * Lecture: Lecture 48
 * Reference: LeetCode 1008 - Construct Binary Search Tree from Preorder Traversal
 * 
 * Description:
 * Reconstruct and return the BST from its preorder traversal array.
 * 
 * Intuition & Approach:
 * Use an upper bound `bound`. Pass index `i` by reference. If `i == preorder.size()` or `preorder[i] > bound`, return NULL. Create node with `preorder[i++]`. Construct left subtree with upper bound `node->val`, and right subtree with previous `bound`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 105 - Construct Tree from Preorder and Inorder
 *   2. LeetCode 449 - Serialize and Deserialize BST
 *   3. GFG - Preorder to BST
 * ======================================================================================
 */

// //construct a bst from a preorder traversal
// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
// };
// TreeNode* bstFromPreorder(vector<int>& A){
//     int i = 0;
//     return build(A,i,INT_MAX);
// }
// TreeNode* build(vector<int>& A,int &i,int bound){
//     if(i == A.size() || A[i] > bound){
//         return NULL;
//     }
//     TreeNode* root = new TreeNode(A[i++]);
//     root->left = build(A,i,root->data);
//     root->right = build(A,i,bound);
//     return root;
// }

// int main(){
//     vector<int> preorder = {8, 5, 1, 7, 10, 12};
//     TreeNode* root = bstFromPreorder(preorder);
//     int i = 0;
//     TreeNode* root = build(preorder, i, INT_MAX);


// }