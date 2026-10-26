/*
 * ======================================================================================
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Lecture: Lecture 34
 * Reference: LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal
 * 
 * Description:
 * Given preorder and inorder traversal arrays, construct and return the unique binary tree.
 * 
 * Intuition & Approach:
 * First element of preorder is the root. Locate root in inorder array using a hash map; all elements to its left belong to left subtree, right belongs to right subtree. Recursively partition and build left and right subtrees.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) with hash map lookup | Space Complexity: O(N) for map and tree
 * 
 * Similar / Related Problems:
 *   1. LeetCode 106 - Construct Tree from Inorder and Postorder
 *   2. LeetCode 889 - Construct Tree from Preorder and Postorder
 *   3. LeetCode 1008 - Construct BST from Preorder
 * ======================================================================================
 */

//construct a binary tree from inorder and preorder traversal
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndexMap);
    }
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorderIndexMap[rootVal];

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + (rootIndex - inStart), inorder, inStart, rootIndex - 1, inorderIndexMap);
        root->right = buildTreeHelper(preorder, preStart + (rootIndex - inStart) + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderIndexMap);

        return root;
    }
};

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

}