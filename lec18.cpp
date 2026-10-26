/*
 * ======================================================================================
 * Problem: Check if Two Binary Trees are Identical / Same Tree
 * Lecture: Lecture 18
 * Reference: LeetCode 100 - Same Tree
 * 
 * Description:
 * Given the roots of two binary trees, write a function to check if they are structurally identical and have the same node values.
 * 
 * Intuition & Approach:
 * Simultaneous recursive traversal. If both are NULL, return true. If one is NULL and other is not, return false. If `p->val != q->val`, return false. Recursively check `isSame(p->left, q->left) && isSame(p->right, q->right)`.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(min(N, M)) | Space Complexity: O(min(H1, H2))
 * 
 * Similar / Related Problems:
 *   1. LeetCode 101 - Symmetric Tree
 *   2. LeetCode 572 - Subtree of Another Tree
 *   3. LeetCode 965 - Univalued Binary Tree
 * ======================================================================================
 */

//check if two tree are idetnical or not
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
bool isSameTree(TreeNode*p, TreeNode*q){
    if(p==NULL && q==NULL){
        return (p==q);
    }
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main(){
    // Create two identical binary trees
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);

    TreeNode* q = new TreeNode(3);
    q->left = new TreeNode(9);
    q->right = new TreeNode(20);
    q->right->left = new TreeNode(15);
    q->right->right = new TreeNode(7);

    if(isSameTree(p, q)){
        cout << "The two trees are identical." << endl;
    } else {
        cout << "The two trees are not identical." << endl;
    }

    return 0;
}