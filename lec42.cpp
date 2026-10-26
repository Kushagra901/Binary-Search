/*
 * ======================================================================================
 * Problem: Floor and Ceil in a Binary Search Tree
 * Lecture: Lecture 42
 * Reference: GFG - Floor in BST & Ceil in BST
 * 
 * Description:
 * Find Floor (greatest value <= key) and Ceil (smallest value >= key) in a Binary Search Tree.
 * 
 * Intuition & Approach:
 * Floor: if `key == root->data`, floor is key. If `key > root->data`, candidate floor is `root->data`, move right to find larger valid floor. If `key < root->data`, move left. Ceil: reverse symmetric logic.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) | Space Complexity: O(1)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 700 - Search in a BST
 *   2. GFG - Inorder Successor in BST
 *   3. LeetCode 270 - Closest Binary Search Tree Value
 * ======================================================================================
 */

//floor and ceiling of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val){
        val=val;
        left=NULL;
        right=NULL; 
    }
};
int floorInBST(TreeNode* root, int key){
    int floor=-1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }
        if(key < root->val){
            floor = root->val;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return floor;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    int key = 5;
    int floorValue = floorInBST(root, key);
    if(floorValue != -1){
        cout << "Floor of " << key << " is: " << floorValue << endl;
    }else{
        cout << "No floor found for " << key << endl;
    }

    return 0;
}