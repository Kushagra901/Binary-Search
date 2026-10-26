/*
 * ======================================================================================
 * Problem: Iterative Postorder Traversal using 2 Stacks
 * Lecture: Lecture 11
 * Reference: LeetCode 145 - Binary Tree Postorder Traversal (2 Stacks)
 * 
 * Description:
 * Iterative postorder traversal (Left -> Right -> Root) using two stacks.
 * 
 * Intuition & Approach:
 * Stack 1 is used to traverse in Root -> Right -> Left order, and each popped node is pushed onto Stack 2. Popping from Stack 2 reverses this sequence into Left -> Right -> Root (exact Postorder).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(2N) = O(N) for two stacks
 * 
 * Similar / Related Problems:
 *   1. LeetCode 145 - Binary Tree Postorder Traversal
 *   2. LeetCode 102 - Binary Tree Level Order Traversal
 *   3. GFG - Postorder Traversal (Iterative)
 * ======================================================================================
 */

//iterative postorder traversal using 2 stacks
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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> preorder;
    if (root == NULL) {
        return preorder;
    }
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL) {
            s1.push(root->left);
        }
        if (root->right != NULL) {
            s1.push(root->right);
        }
    }
    while (!s2.empty()) {
        preorder.push_back(s2.top()->val);
        s2.pop();
    }
    return preorder;
}

int main(){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

}