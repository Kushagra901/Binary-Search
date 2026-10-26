/*
 * ======================================================================================
 * Problem: Insert a Node in a Binary Search Tree
 * Lecture: Lecture 43
 * Reference: LeetCode 701 - Insert into a Binary Search Tree
 * 
 * Description:
 * Insert a given value into the BST such that the tree remains a valid BST.
 * 
 * Intuition & Approach:
 * Traverse from root comparing `val` with current node. If `val > curr->val`, move right; if right is NULL, attach new node there. If `val < curr->val`, move left; if left is NULL, attach new node there.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) | Space Complexity: O(1) iterative
 * 
 * Similar / Related Problems:
 *   1. LeetCode 700 - Search in a BST
 *   2. LeetCode 450 - Delete Node in a BST
 *   3. LeetCode 1008 - Construct BST from Preorder Traversal
 * ======================================================================================
 */

//insert node in a given position in a binary search tree
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };

// TreeNode* insertNode(TreeNode* root, int val) {
//     if (root == nullptr) {
//         return new TreeNode(val);
//     }

//     TreeNode* curr = root;

//     while (true) {
//         if (val >= curr->val) {  // duplicates go right
//             if (curr->right == nullptr) {
//                 curr->right = new TreeNode(val);
//                 break;
//             }
//             curr = curr->right;
//         } 
//         else {
//             if (curr->left == nullptr) {
//                 curr->left = new TreeNode(val);
//                 break;
//             }
//             curr = curr->left;
//         }
//     }

//     return root;
// }

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int key) {
    if (root == NULL) {
    return new Node(key);
        Node* curr = root;
        while (true) {
            if (key >= curr->data) {  // duplicates go right
                if (curr->right == NULL) {
                    curr->right = new Node(key);
                    break;
                }
                curr = curr->right;
            } else {
                if (curr->left == NULL) {
                    curr->left = new Node(key);
                    break;
                }
                curr = curr->left;
            }
        }
    }
    return root;
}



//coding  ninjas
// TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
// {
//     if(root==NULL){
//         return new TreeNode<int>(val);
//     }
//     TreeNode<int>* curr=root;
//     while(true){
//         if(curr->val <= val){
//             if(curr->right==NULL){
//                 curr->right = new TreeNode<int>(val);
//                 break;
//             }else{
//                 curr = curr->right;
//             }
//         }else{
//             if(curr->left != NULL) curr = curr->left;
//             else{
//                 curr->left = new TreeNode<int>(val);
//                 break;
//             }
//         }
//     }
//     return root;
// }
// int main(){
//     TreeNode* root = new TreeNode(4);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(6);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(3);
//     root->right->left = new TreeNode(5);
//     root->right->right = new TreeNode(7);

//     int valToInsert = 8;
//     root = insertNode(root, valToInsert);

//     // Print the tree in-order to verify insertion
//     function<void(TreeNode*)> inOrderTraversal = [&](TreeNode* node) {
//         if (node == nullptr) return;
//         inOrderTraversal(node->left);
//         cout << node->val << " ";
//         inOrderTraversal(node->right);
//     };

//     cout << "In-order traversal after insertion: ";
//     inOrderTraversal(root);
//     cout << endl;

//     return 0;
// }