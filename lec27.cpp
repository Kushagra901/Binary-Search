/*
 * ======================================================================================
 * Problem: Lowest Common Ancestor (LCA) in Binary Tree
 * Lecture: Lecture 27
 * Reference: LeetCode 236 - Lowest Common Ancestor of a Binary Tree
 * 
 * Description:
 * Find the lowest common ancestor node of two given nodes p and q in a binary tree.
 * 
 * Intuition & Approach:
 * Base cases: if `root == NULL || root == p || root == q`, return root. Recursively search left and right subtrees. If both left and right return non-NULL, current node is the LCA. If only one returns non-NULL, propagate that node upwards.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 235 - Lowest Common Ancestor of a BST
 *   2. LeetCode 1644 - Lowest Common Ancestor of a Binary Tree II
 *   3. LeetCode 1650 - Lowest Common Ancestor of a Binary Tree III
 * ======================================================================================
 */

//lowest common ancestor of two nodes in a binary tree
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

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if(root == NULL || root == p || root == q){
//         return root;
//     }       
//     TreeNode* left = lowestCommonAncestor(root->left, p, q);
//     TreeNode* right = lowestCommonAncestor(root->right, p, q);
//     if(left == NULL) return right;
//     else if(right == NULL) return left;
//     else return root;
// }

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data=x;
        left=NULL;
        right=NULL; 
    }
};
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root == NULL) return -1;
    if(root->data == x || root->data == y) return root->data;

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if(left != -1 && right != -1) return root->data;
    else if(left != -1) return left;
    else return right;
}


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if(lca != NULL){
        cout << "Lowest Common Ancestor: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    return 0;
}