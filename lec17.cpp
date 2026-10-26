/*
 * ======================================================================================
 * Problem: Binary Tree Maximum Path Sum
 * Lecture: Lecture 17
 * Reference: LeetCode 124 - Binary Tree Maximum Path Sum
 * 
 * Description:
 * Find the maximum path sum of any non-empty path in a binary tree. A path can start and end at any node.
 * 
 * Intuition & Approach:
 * At each node, calculate maximum branch sum from left and right: `max(0, helper(node->left))`. The max path through the current node is `node->val + leftGain + rightGain`. Update global maximum, and return `node->val + max(leftGain, rightGain)` for parents.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 543 - Diameter of Binary Tree
 *   2. LeetCode 112 - Path Sum
 *   3. LeetCode 113 - Path Sum II
 *   4. LeetCode 437 - Path Sum III
 * ======================================================================================
 */

//max path sum in binary tree
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

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathSum(root, maxi); 
    return maxi;     
    }
    int maxPathSum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }
        int left = max(0, maxPathSum(root->left, maxi));//-ve values are not considered in the path sum, so we take max with 0
        int right = max(0, maxPathSum(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }

int main(){
    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<maxPathSum(root)<<endl;
    return 0;
}