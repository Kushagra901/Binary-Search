/*
 * ======================================================================================
 * Problem: Recover Binary Search Tree (Two Swapped Nodes)
 * Lecture: Lecture 52
 * Reference: LeetCode 99 - Recover Binary Search Tree
 * 
 * Description:
 * Two elements of a BST are swapped by mistake. Recover the tree without changing its structure.
 * 
 * Intuition & Approach:
 * Inorder traversal of BST should be sorted. Maintain `prev`, `first`, `middle`, and `last` pointers. When `prev->val > curr->val`: if first violation, mark `first = prev` and `middle = curr`. If second violation, mark `last = curr`. If non-adjacent, swap `first` and `last`. If adjacent, swap `first` and `middle`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion (or O(1) with Morris traversal)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 98 - Validate Binary Search Tree
 *   2. LeetCode 173 - BST Iterator
 *   3. GFG - Fix BST with Two Nodes Swapped
 * ======================================================================================
 */

//recover bst
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    private:
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != NULL && (root -> val < first -> val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
}
public:
void recoverTree(TreeNode* root) {
    first = middle = last =  NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val, last->val);
    else if(first && middle) swap(first->val, middle->val);
}
};

int main()  {
    Solution s; 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    s.recoverTree(root);
    return 0;
}