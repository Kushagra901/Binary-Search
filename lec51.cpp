/*
 * ======================================================================================
 * Problem: Two Sum in a Binary Search Tree (Find Pair with Target Sum)
 * Lecture: Lecture 51
 * Reference: LeetCode 653 - Two Sum IV - Input is a BST
 * 
 * Description:
 * Given the root of a Binary Search Tree and target sum k, return true if there exist two elements in the BST such that their sum equals k.
 * 
 * Intuition & Approach:
 * Simulate Two-Pointer approach on BST without storing entire traversal in O(N) array! Use two BSTIterators: one for normal ascending inorder (next()) and another for reverse descending inorder (before()). Check `i + j == k`, increment left or decrement right.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(2 * H) = O(H) auxiliary space for two iterators
 * 
 * Similar / Related Problems:
 *   1. LeetCode 1 - Two Sum
 *   2. LeetCode 167 - Two Sum II - Input Array Is Sorted
 *   3. LeetCode 173 - BST Iterator
 * ======================================================================================
 */

//two sum ib bst
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
    bool reverse = true;
public:

BSTIterator(TreeNode* root, bool isReverse) {
    reverse = isReverse;
    pushAll(root);
}
bool hasNext() {
    return !myStack.empty();
}

int next(){
    TreeNode* temp = myStack.top();
    myStack.pop();
    if(!reverse) pushAll(temp->right);
    else pushAll(temp->left);
    return temp->data;
}
private:
void pushAll(TreeNode* node) {
    while (node != nullptr) {
        myStack.push(node);
        if(reverse) node = node->right;
        else node = node->left;
    }
}
};

class Solution {
    public: 
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }  
};
int main(){

}