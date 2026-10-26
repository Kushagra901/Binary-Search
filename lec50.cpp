/*
 * ======================================================================================
 * Problem: Binary Search Tree Iterator
 * Lecture: Lecture 50
 * Reference: LeetCode 173 - Binary Search Tree Iterator
 * 
 * Description:
 * Implement the BSTIterator class that represents an iterator over the in-order traversal of a BST with next() and hasNext() operations in O(1) amortized time and O(H) memory.
 * 
 * Intuition & Approach:
 * Controlled recursion using an explicit stack: In constructor, push root and all its left children to stack. In `next()`, pop top node, push all left descendants of its right child, and return node data. `hasNext()` checks `!stack.empty()`.
 * 
 * Complexity Analysis:
 * - Time Complexity: next() is O(1) amortized, hasNext() is O(1) | Space Complexity: O(H) memory
 * 
 * Similar / Related Problems:
 *   1. LeetCode 653 - Two Sum IV - Input is a BST
 *   2. LeetCode 1586 - Binary Search Tree Iterator II
 *   3. LeetCode 251 - Flatten 2D Vector
 * ======================================================================================
 */

//binary search tree iterator
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    bool hasNext() {
        return !myStack.empty();
    }
    int next() {
        TreeNode* node = myStack.top();
        myStack.pop();
        pushAll(node->right);
        return node->data;
    }
    private:
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = node->left;
        }
    }
};


int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    return 0;
}