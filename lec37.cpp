/*
 * ======================================================================================
 * Problem: Morris Traversal (Inorder & Preorder with O(1) Space)
 * Lecture: Lecture 37
 * Reference: LeetCode 94 / 144 - Morris Traversal (Threaded Binary Tree)
 * 
 * Description:
 * Traverse binary tree in inorder and preorder in O(N) time using O(1) auxiliary space without recursion or stack using Threaded Binary Tree concept.
 * 
 * Intuition & Approach:
 * For each node, find its inorder predecessor (rightmost node in left subtree). If `predecessor->right == NULL`, create thread `predecessor->right = curr` and move `curr = curr->left`. If `predecessor->right == curr`, cut thread, visit `curr`, and move `curr = curr->right`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) amortized (each edge traversed at most 3 times) | Space Complexity: O(1) auxiliary space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 94 - Binary Tree Inorder Traversal
 *   2. LeetCode 144 - Binary Tree Preorder Traversal
 *   3. LeetCode 99 - Recover Binary Search Tree
 * ======================================================================================
 */

//morris traversal inorder and preorder
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL; 
    }
};
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
}
    
vector<int> getPreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}

int main(){ 
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

    vector<int> inorder=getInorder(root);
    vector<int> preorder=getPreorder(root);

    cout<<"Inorder: ";
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    cout<<"Preorder: ";
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }
    cout<<endl;
}