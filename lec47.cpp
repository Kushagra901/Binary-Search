/*
 * ======================================================================================
 * Problem: Lowest Common Ancestor (LCA) in a Binary Search Tree
 * Lecture: Lecture 47
 * Reference: LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree
 * 
 * Description:
 * Find the lowest common ancestor of two nodes in a Binary Search Tree.
 * 
 * Intuition & Approach:
 * Utilize BST property: If both `p->val` and `q->val` are less than `root->val`, LCA lies in left subtree. If both are greater, LCA lies in right subtree. The first node where split occurs (or equals p or q) is the LCA.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) | Space Complexity: O(1) iterative
 * 
 * Similar / Related Problems:
 *   1. LeetCode 236 - Lowest Common Ancestor of a Binary Tree
 *   2. LeetCode 1644 - Lowest Common Ancestor of a Binary Tree II
 *   3. GFG - LCA in BST
 * ======================================================================================
 */

//lca in bst
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
TreeNode LowestCommonAncestor(TreeNode root, TreeNode* p, TreeNode* q){
    if(root == NULL){
        return NULL;
    }
    int curr = root->data;
    if(curr < p->data && curr < q->data){
        return LowestCommonAncestor(root->right, p, q);
    }
    if(curr > p->data && curr > q->data){
        return LowestCommonAncestor(root->left, p, q);
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = LowestCommonAncestor(root, p, q);
    if(lca != NULL){
        cout << "LCA: " << lca->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }
    return 0;
}