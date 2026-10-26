/*
 * ======================================================================================
 * Problem: Flatten Binary Tree to Linked List In-Place
 * Lecture: Lecture 38
 * Reference: LeetCode 114 - Flatten Binary Tree to Linked List
 * 
 * Description:
 * Flatten a binary tree into a 'linked list' in-place where left pointer is always NULL and right pointer points to next node in preorder.
 * 
 * Intuition & Approach:
 * Can be solved using Morris-like approach: while `curr` exists, if `curr->left` exists, find rightmost node of `curr->left`, point its right to `curr->right`, then move `curr->right = curr->left` and `curr->left = NULL`. Advance `curr = curr->right`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(1) auxiliary space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 430 - Flatten a Multilevel Doubly Linked List
 *   2. LeetCode 116 - Populating Next Right Pointers in Each Node
 *   3. GFG - Flatten Binary Tree
 * ======================================================================================
 */

//flatten a binary tree to a linked list in place
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
void flatten(TreeNode* root) {
        TreeNode* current = root;

        while (current != nullptr) {

            if (current->left != nullptr) {
                TreeNode* rightmost =
                    current->left;

                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                rightmost->right =
                    current->right;
                current->right =
                    current->left;
                current->left = nullptr;
            }

            current = current->right;
        }
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    // Print the flattened linked list
    TreeNode* curr = root;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}