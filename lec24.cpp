/*
 * ======================================================================================
 * Problem: Right / Left View of Binary Tree
 * Lecture: Lecture 24
 * Reference: LeetCode 199 - Binary Tree Right Side View
 * 
 * Description:
 * Find the nodes visible from the right side (or left side) of a binary tree from top to bottom.
 * 
 * Intuition & Approach:
 * Recursive Reverse Preorder (Root -> Right -> Left) for Right View. Pass current level `lvl`. If `lvl == result.size()`, this is the first node encountered at this level; add to result. (For Left View, use Root -> Left -> Right).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. GFG - Left View of Binary Tree
 *   2. LeetCode 102 - Binary Tree Level Order Traversal
 *   3. LeetCode 545 - Boundary of Binary Tree
 * ======================================================================================
 */

//right/left view of binary tree
#include <bits/stdc++.h>
using namespace std;

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
// void recursive(TreeNode* root, vector<int>& res, int level) {
//     if (root == NULL) {
//         return;
//     }
//     if (level == res.size()) {
//         res.push_back(root->data);
//     }
//     recursive(root->right, res, level + 1);
//     recursive(root->left, res, level + 1);
// }
// vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         recursive(root, res, 0);
//         return res;      
//     }

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x){
        data=x;
        left=NULL;
        right=NULL; 
    }
};

vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> result;
    if (!root) return result;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if (i == n - 1) {
                result.push_back(node->data);
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return result;
}


int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->right = new BinaryTreeNode(4);
    root->left->right->right = new BinaryTreeNode(5);
    root->left->right->right->right = new BinaryTreeNode(6);

    vector<int> result = rightSideView(root);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}