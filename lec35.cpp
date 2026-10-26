/*
 * ======================================================================================
 * Problem: Construct Binary Tree from Inorder and Postorder Traversal
 * Lecture: Lecture 35
 * Reference: LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal
 * 
 * Description:
 * Given inorder and postorder traversal arrays, reconstruct the unique binary tree.
 * 
 * Intuition & Approach:
 * The last element of postorder is always the root. Locate it in inorder via map to count left subtree elements. Recursively construct the right subtree, then left subtree.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(N)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 105 - Construct Tree from Preorder and Inorder
 *   2. LeetCode 889 - Construct Tree from Preorder and Postorder
 *   3. GFG - Tree from Inorder and Postorder
 * ======================================================================================
 */

// Construct a binary tree from inorder and postorder traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    if(inorder.size() != postorder.size()) return NULL;

    map<int, int> inorderMap;
    for(int i = 0; i < inorder.size(); i++){
        inorderMap[inorder[i]] = i;
    }
    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
} 
TreeNode* buildTreePostIn(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,map<int,int>& hm){
    if(ps > pe || is > ie) return NULL;
    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;
    root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);
    root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);
    return root;
}
int main(){
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
}