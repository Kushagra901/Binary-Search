/*
 * ======================================================================================
 * Problem: Print Root to Node Path in Binary Tree
 * Lecture: Lecture 26
 * Reference: LeetCode 257 - Binary Tree Paths / InterviewBit - Path to Given Node
 * 
 * Description:
 * Find and print the sequence of node values along the path from the root node to a target node value.
 * 
 * Intuition & Approach:
 * DFS backtracking: Add current node to vector. If current node is target, return true. Recursively search left or right. If both return false, backtrack by popping the current node from vector and return false.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack and path array
 * 
 * Similar / Related Problems:
 *   1. LeetCode 257 - Binary Tree Paths
 *   2. LeetCode 236 - Lowest Common Ancestor of a Binary Tree
 *   3. LeetCode 113 - Path Sum II
 * ======================================================================================
 */

//print root to node path
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode{
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x){
//         data=x;
//         left=NULL;
//         right=NULL; 
//     }
// };
// class Solution {
//     public:
// bool getPath(TreeNode* root,vector<int>&arr,int x)
// {
//     if(!root) return false;
//     arr.push_back(root->data);
//     if(root->data==x) return true;
//     if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;
//     arr.pop_back();
//     return false;
// }
// public:
// vector<int> solve(TreeNode* A, int B){
//     vector<int> arr;
//     if(getPath(A,arr,B)) return arr;
//     getPath(A,arr,B);
//     return arr;
// }
// };

template <typename T>
class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void allRootLeafHelper(BinaryTreeNode<int> *root, string path, vector<string> &result);

vector<string> allRootLeaf(BinaryTreeNode<int> *root){
    vector<string> result;
    if(!root) return result;

    string path = "";
    allRootLeafHelper(root, path, result);
    return result;
}

void allRootLeafHelper(BinaryTreeNode<int> *root, string path, vector<string> &result){
    if(!root) return;

    path += to_string(root->data);

    if(!root->left && !root->right){
        result.push_back(path);
        return;
    }

    allRootLeafHelper(root->left, path + "->", result);
    allRootLeafHelper(root->right, path + "->", result);
}

int main() {

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    vector<string> paths = allRootLeaf(root);
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}