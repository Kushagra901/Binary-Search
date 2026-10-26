/*
 * ======================================================================================
 * Problem: Binary Tree Zigzag (Spiral) Level Order Traversal
 * Lecture: Lecture 19
 * Reference: LeetCode 103 - Binary Tree Zigzag Level Order Traversal
 * 
 * Description:
 * Return the zigzag level order traversal of binary tree node values (alternating left-to-right and right-to-left).
 * 
 * Intuition & Approach:
 * Use standard BFS queue level-by-level. Maintain a boolean flag `leftToRight`. Pre-allocate vector of level size, and insert elements at index `i` (if left-to-right) or `size - 1 - i` (if right-to-left). Flip flag after each level.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(N) queue and output
 * 
 * Similar / Related Problems:
 *   1. LeetCode 102 - Binary Tree Level Order Traversal
 *   2. LeetCode 107 - Level Order Traversal II
 *   3. GFG - Spiral Level Order Traversal
 * ======================================================================================
 */

//zig-zag traversal of a binary tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigZagTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL) {
        return result;
    }
    queue<TreeNode*>nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while(!nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for(int i=0; i<size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = node->val;
            if(node->left) {
                nodesQueue.push(node->left);
            }
            if(node->right) {
                nodesQueue.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigZagTraversal(root);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}