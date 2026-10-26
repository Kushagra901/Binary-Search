/*
 * ======================================================================================
 * Problem: Level Order Traversal / Breadth First Search (BFS)
 * Lecture: Lecture 8
 * Reference: LeetCode 102 - Binary Tree Level Order Traversal
 * 
 * Description:
 * Traverse the tree level by level from top to bottom and left to right using a queue.
 * 
 * Intuition & Approach:
 * Use a FIFO queue. Push the root. In each step, record the current queue size (number of nodes in the current level), pop each node, add its value to the level list, and push its non-null left and right children.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(W) where W is maximum width of tree (O(N/2) = O(N) at leaf level)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 107 - Binary Tree Level Order Traversal II
 *   2. LeetCode 103 - Binary Tree Zigzag Level Order Traversal
 *   3. LeetCode 637 - Average of Levels in Binary Tree
 *   4. LeetCode 199 - Binary Tree Right Side View
 * ======================================================================================
 */

//level order traversal of binary tree
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;      
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}