/*
 * ======================================================================================
 * Problem: Maximum Width of Binary Tree
 * Lecture: Lecture 28
 * Reference: LeetCode 662 - Maximum Width of Binary Tree
 * 
 * Description:
 * Calculate the maximum width of a binary tree (maximum number of nodes between leftmost and rightmost non-null nodes at any level, including null nodes in between).
 * 
 * Intuition & Approach:
 * Assign 0-based indices as in a heap: left child is `2 * idx + 1`, right is `2 * idx + 2`. To prevent integer overflow at deep levels, subtract minimum index of current level before calculating child indices. Level width = `last_idx - first_idx + 1`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(N) for BFS queue
 * 
 * Similar / Related Problems:
 *   1. LeetCode 102 - Binary Tree Level Order Traversal
 *   2. LeetCode 104 - Maximum Depth of Binary Tree
 *   3. GFG - Width of Binary Tree
 * ======================================================================================
 */

//maximum width of bt
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data=x;
        left=NULL;
        right=NULL; 
    }
};

int witdthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int minIndex = q.front().second;
        int first, last;
        for(int i=0; i<size; i++){
            int cur_id = q.front().second - minIndex;
            TreeNode* node = q.front().first;
            q.pop();
            if(i==0) first = cur_id;
            if(i==size-1) last = cur_id;
            if(node->left) q.push({node->left, cur_id*2+1});
            if(node->right) q.push({node->right, cur_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << witdthOfBinaryTree(root) << endl;
    return 0;
}