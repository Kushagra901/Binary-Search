/*
 * ======================================================================================
 * Problem: Kth Smallest / Largest Element in a BST
 * Lecture: Lecture 45
 * Reference: LeetCode 230 - Kth Smallest Element in a BST
 * 
 * Description:
 * Find the kth smallest and kth largest element in a Binary Search Tree.
 * 
 * Intuition & Approach:
 * Inorder traversal of BST gives sorted ascending order. Maintain counter during inorder traversal; when `count == k`, record node. For kth largest, either use reverse inorder (Right -> Root -> Left) or find `(N - k + 1)th` smallest.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(min(H, k)) | Space Complexity: O(H) recursion/stack (O(1) with Morris)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 94 - Binary Tree Inorder Traversal
 *   2. GFG - Kth Largest Element in BST
 *   3. LeetCode 653 - Two Sum IV - Input is a BST
 * ======================================================================================
 */

//kth largest/smallest element in bst
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
int countSmallest = 0;
int countLargest = 0;
int kthSmallest = -1;
int kthLargest = -1;

void findSmallest(TreeNode* root, int k){
    if(root == NULL || countSmallest >= k){
        return;
    }
    findSmallest(root->left, k);
    countSmallest++;
    if(countSmallest == k){
        kthSmallest = root->data;
        return;
    }
    findSmallest(root->right, k);
}
void largest(TreeNode* root, int k){
    if(root == NULL || countLargest >= k){
        return;
    }
    largest(root->right, k);
    countLargest++;
    if(countLargest == k){
        kthLargest = root->data;
        return;
    }
    largest(root->left, k);
}
vector<int> findKthElements(TreeNode* root, int k){
    findSmallest(root, k);
    largest(root, k);
    return {kthSmallest, kthLargest};

    vector<int> result(2);
    result[0] = kthSmallest;
    result[1] = kthLargest;

    return result;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    vector<int> result = findKthElements(root, 3);
    cout << "3rd smallest: " << result[0] << ", 3rd largest: " << result[1] << endl;

    return 0;
}