/*
 * ======================================================================================
 * Problem: Bottom View of Binary Tree
 * Lecture: Lecture 23
 * Reference: GFG - Bottom View of Binary Tree
 * 
 * Description:
 * Find the nodes visible when looking at the tree from the bottom along vertical coordinate lines.
 * 
 * Intuition & Approach:
 * Use level order traversal with vertical column coordinate `line`. Overwrite map entries `map[line] = node->data` as we proceed down levels so that the deepest node at each column remains.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N log N) using std::map | Space Complexity: O(N)
 * 
 * Similar / Related Problems:
 *   1. GFG - Top View of Binary Tree
 *   2. LeetCode 987 - Vertical Order Traversal
 *   3. LeetCode 199 - Binary Tree Right Side View
 * ======================================================================================
 */

//bottom view of the binary tree
#include <bits/stdc++.h>
using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     Node(int x){
//         data=x;
//         left=NULL;
//         right=NULL; 
//     }
// };

// vector<int> bottomView(Node* root) {
//     vector<int> ans;
//     if(root == NULL) return ans;
//     map<int, int> mpp;
//     queue<pair<Node*, int>> q;
//     q.push({root, 0});
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
//         Node* node = it.first;
//         int line = it.second;
//         mpp[line] = node->data;
//         if(node->left) {
//             q.push({node->left, line - 1});
//         }
//         if(node->right) {
//             q.push({node->right, line + 1});
//         }
//     }
//     for(auto it : mpp) {
//         ans.push_back(it.second);
//     }
//     return ans;
// }
// struct TreeNode{
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x){
//         data=x;
//         left=NULL;
//         right=NULL; 
//     }
// };
// vector<int> bottomView(TreeNode<int> * root){
//     vector<int> ans;
//     if(root == NULL) return ans;
//     map<int, int> mpp;
//     queue<pair<TreeNode*, int>> q;
//     q.push({root, 0});
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
//         TreeNode* node = it.first;
//         int line = it.second;
//         mpp[line] = node->data;
//         if(node->left) {
//             q.push({node->left, line - 1});
//         }
//         if(node->right) {
//             q.push({node->right, line + 1});
//         }
//     }
//     for(auto it : mpp) {
//         ans.push_back(it.second);
//     }
//     return ans;
// }


// int main(){
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->right = new Node(4);
//     root->left->right->right = new Node(5);
//     root->left->right->right->right = new Node(6);

//     vector<int> result = bottomView(root);
//     for(int val : result){
//         cout << val << " ";
//     }
//     return 0;
// }