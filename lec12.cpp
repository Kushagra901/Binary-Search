/*
 * ======================================================================================
 * Problem: Iterative Postorder Traversal using 1 Stack
 * Lecture: Lecture 12
 * Reference: LeetCode 145 - Binary Tree Postorder Traversal (1 Stack)
 * 
 * Description:
 * Optimized iterative postorder traversal using only a single stack.
 * 
 * Intuition & Approach:
 * Go left as much as possible pushing nodes. When left is exhausted, inspect right child without popping. If right child exists and hasn't been visited, move to right. Otherwise, pop and process current node, and handle backtracking through right subtrees.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(2N) = O(N) | Space Complexity: O(H) for single stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 144 - Preorder Traversal Iterative
 *   2. LeetCode 94 - Inorder Traversal Iterative
 *   3. LeetCode 114 - Flatten Binary Tree to Linked List
 * ======================================================================================
 */

//iterative postorder traversal of binary tree usign 1 stack
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
vector<int> postOrder(TreeNode* node){
    vector<int> post;
    if(node == NULL){
        return post;
    }

    stack<TreeNode*> st;
    TreeNode* cur = node;
    TreeNode* lastVisited = NULL;

    while(cur != NULL || !st.empty()){
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        } else {
            TreeNode* peekNode = st.top();
            if(peekNode->right != NULL && lastVisited != peekNode->right){
                cur = peekNode->right;
            } else {
                post.push_back(peekNode->val);
                lastVisited = peekNode;
                st.pop();
            }
        }
    }

    return post;
}


int main(){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postOrder(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}