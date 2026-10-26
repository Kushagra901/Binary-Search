/*
 * ======================================================================================
 * Problem: Preorder, Inorder, and Postorder Traversals in a Single Pass
 * Lecture: Lecture 13
 * Reference: Coding Ninjas - Tree Traversals (All-in-One)
 * 
 * Description:
 * Obtain Preorder, Inorder, and Postorder sequences simultaneously in a single traversal pass using a stack of pairs (node, state).
 * 
 * Intuition & Approach:
 * Push `pair<TreeNode*, int>(root, 1)`. If `state == 1`, add to preorder, increment state to 2, and push left child. If `state == 2`, add to inorder, increment state to 3, and push right child. If `state == 3`, add to postorder and pop.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(3N) = O(N) | Space Complexity: O(4N) for stack and result vectors
 * 
 * Similar / Related Problems:
 *   1. LeetCode 144, 94, 145 - Binary Tree Traversals
 *   2. GFG - All in One Tree Traversal
 * ======================================================================================
 */

// //all traversal in one
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x){
//         val=x;
//         left=NULL;
//         right=NULL; 
//     }
// };
// vector<int> allTraversal(TreeNode* root) {
//     stack<pair<TreeNode*, int>> st;
//     st.push({root, 1});
//     vector<int> pre, in, post;
//     if (root == NULL) {
//         return {};
//     }
//     while(!st.empty()){
//         auto it = st.top();
//         st.pop();

//         if(it.second == 1){
//             pre.push_back(it.first->val);
//             it.second++;
//             st.push(it);
//             if(it.first->left != NULL){
//                 st.push({it.first->left, 1});
//             }
//         } else if(it.second == 2){
//             in.push_back(it.first->val);
//             it.second++;
//             st.push(it);
//             if(it.first->right != NULL){
//                 st.push({it.first->right, 1});
//             }
//         } else {
//             post.push_back(it.first->val);
//         }
//     }
//     for(int i = 0; i < post.size(); i++){
//         pre.push_back(post[i]);
//     }
//     return pre;
// }

// int main(){
//     struct TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     vector<int> result = allTraversal(root);
//     for (int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }



//extra 
// get tree from inorder and preorder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     struct TreeNode {
//         int val;
//         TreeNode *left;
//         TreeNode *right;
//         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     };
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if (preorder.empty() || inorder.empty()) {
//             return nullptr;
//         }

//         unordered_map<int, int> inorderIndexMap;
//         for (int i = 0; i < inorder.size(); ++i) {
//             inorderIndexMap[inorder[i]] = i;
//         }

//         return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndexMap);
//     }
// private:
//     TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
//         if (preStart > preEnd || inStart > inEnd) {
//             return nullptr;
//         }

//         int rootVal = preorder[preStart];
//         TreeNode* root = new TreeNode(rootVal);
//         int rootIndex = inorderIndexMap[rootVal];

//         root->left = buildTreeHelper(preorder, preStart + 1, preStart + (rootIndex - inStart), inorder, inStart, rootIndex - 1, inorderIndexMap);
//         root->right = buildTreeHelper(preorder, preStart + (rootIndex - inStart) + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderIndexMap);

//         return root;
//     }
// };

void buildPostorder(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap, vector<int>& postorder) {
    if (preStart > preEnd || inStart > inEnd) {
        return;
    }

    int rootVal = preorder[preStart];
    int rootIndex = inorderIndexMap[rootVal];

    buildPostorder(preorder, preStart + 1, preStart + (rootIndex - inStart), inorder, inStart, rootIndex - 1, inorderIndexMap, postorder);
    buildPostorder(preorder, preStart + (rootIndex - inStart) + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderIndexMap, postorder);

    postorder.push_back(rootVal);
}

vector<int> getPostorder(vector<int>& inorder, vector<int>& preorder){
    
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inorderIndexMap[inorder[i]] = i;
    }

    vector<int> postorder;
    buildPostorder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndexMap, postorder);
    return postorder;
}
int main() {
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> preorder = {1, 2, 4, 5, 3};

    vector<int> postorder = getPostorder(inorder, preorder);

    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}