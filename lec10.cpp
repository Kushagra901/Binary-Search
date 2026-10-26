/*
 * ======================================================================================
 * Problem: Iterative Inorder Traversal of Binary Tree
 * Lecture: Lecture 10
 * Reference: LeetCode 94 - Binary Tree Inorder Traversal (Iterative)
 * 
 * Description:
 * Perform inorder traversal (Left -> Root -> Right) iteratively using an explicit stack without recursion.
 * 
 * Intuition & Approach:
 * Maintain a pointer `curr = root`. Push `curr` and go left as far as possible (`curr = curr->left`). When NULL is reached, pop from stack, print/record top node, and move to its right (`curr = node->right`). Repeat until stack is empty and curr is NULL.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 173 - BST Iterator
 *   2. LeetCode 230 - Kth Smallest Element in a BST
 *   3. LeetCode 98 - Validate Binary Search Tree
 * ======================================================================================
 */

//iterative inorder traversal of binary tree
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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        result.push_back(current->val);

        current = current->right;
    }

    return result;
}
int main(){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = inorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}