/*
 * ======================================================================================
 * Problem: Largest BST in Binary Tree
 * Lecture: Lecture 53
 * Reference: LeetCode 333 / GFG - Largest BST in Binary Tree
 * 
 * Description:
 * Find the size (number of nodes) of the largest subtree that is also a valid Binary Search Tree.
 * 
 * Intuition & Approach:
 * Bottom-up postorder traversal returning a tuple/struct `(maxSize, minNode, maxNode)`. A node forms a BST if `left.maxNode < node->data < right.minNode`. If valid BST, size is `1 + left.size + right.size`. If invalid, return `max(left.size, right.size)` and set bounds to invalid (-INF, +INF).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) single-pass bottom-up | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 98 - Validate Binary Search Tree
 *   2. LeetCode 1373 - Maximum Sum BST in Binary Tree
 *   3. GFG - Largest BST
 * ======================================================================================
 */

// largest bst in binary tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
class NodeValue {
    public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;

    }
};
class Solution{
    private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        if(left.maxNode < root->val && root->val < right.minNode){
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
        int largestBSTSubtree(TreeNode* root){
            return largestBSTSubtreeHelper(root).maxSize;
        }
    };


int main(){

}