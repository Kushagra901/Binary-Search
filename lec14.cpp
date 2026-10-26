/*
 * ======================================================================================
 * Problem: Maximum Depth / Height of Binary Tree
 * Lecture: Lecture 14
 * Reference: LeetCode 104 - Maximum Depth of Binary Tree
 * 
 * Description:
 * Find the maximum number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * Intuition & Approach:
 * Divide and conquer: `1 + max(maxDepth(root->left), maxDepth(root->right))`. Base case: if root is NULL, depth is 0.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursive stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 111 - Minimum Depth of Binary Tree
 *   2. LeetCode 559 - Maximum Depth of N-ary Tree
 *   3. LeetCode 110 - Balanced Binary Tree
 * ======================================================================================
 */

//maximum depth of the tree
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
int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main(){
    // Create a simple binary tree
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum depth of the tree: " << maxDepth(root) << endl;

    return 0;
}