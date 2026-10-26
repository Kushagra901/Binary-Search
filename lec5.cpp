/*
 * ======================================================================================
 * Problem: Preorder Traversal of Binary Tree (Recursive)
 * Lecture: Lecture 5
 * Reference: LeetCode 144 - Binary Tree Preorder Traversal
 * 
 * Description:
 * Traverse a binary tree in preorder sequence: Visit Root -> Left Subtree -> Right Subtree recursively.
 * 
 * Intuition & Approach:
 * In Preorder traversal, we process the current node first, then recursively traverse its left subtree, and finally its right subtree. Base case: If node is NULL, return.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) where N is number of nodes | Space Complexity: O(H) auxiliary recursion stack where H is tree height (O(N) worst case)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 94 - Binary Tree Inorder Traversal
 *   2. LeetCode 145 - Binary Tree Postorder Traversal
 *   3. LeetCode 589 - N-ary Tree Preorder Traversal
 * ======================================================================================
 */

//preorder traversal of binary tree
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
// void preorder(struct Node* root){
//     if(root==NULL){
//         return;
//     }
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right!=NULL){
            st.push(node->right);
        }
        if(node->left!=NULL){
            st.push(node->left);
        }
    }
    return ans;
}

int main(){
    struct TreeNode* root = new struct TreeNode(1);
    root->left = new struct TreeNode(2);
    root->right = new struct TreeNode(3);
    vector<int> result = preorderTraversal(root);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

}