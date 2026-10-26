/*
 * ======================================================================================
 * Problem: Inorder Predecessor and Successor in BST
 * Lecture: Lecture 49
 * Reference: LeetCode 285 - Inorder Successor in BST / GFG Predecessor and Successor
 * 
 * Description:
 * Find the in-order predecessor and successor of a given key in a Binary Search Tree.
 * 
 * Intuition & Approach:
 * Successor: If `root->val > key`, candidate successor is root, move left `root = root->left`. If `root->val <= key`, move right. Predecessor: If `root->val < key`, candidate predecessor is root, move right. If `root->val >= key`, move left.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(H) | Space Complexity: O(1) auxiliary space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 510 - Inorder Successor in BST II
 *   2. LeetCode 700 - Search in a BST
 *   3. GFG - Closest Neighbor in BST
 * ======================================================================================
 */

//Inorder Successor/Predecessor in BST

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//     TreeNode* successor = NULL;
//     while (root != NULL) {
//         if (p->data < root->data) {
//             successor = root;
//             root = root->left;
//         } else {
//             root = root->right;
//         }
//     }
//     return successor;
    
// }
// TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
//     TreeNode* predecessor = NULL;
//     while (root != NULL) {
//         if (p->data > root->data) {
//             predecessor = root;
//             root = root->right;
//         } else {
//             root = root->left;
//         }
//     }
//     return predecessor;
// }

// int findDist(Node* root, int a, int b) {
//       if(root == NULL) {
//           return 0;
//       }
//         if(root->data > a && root->data > b) {
//             return findDist(root->left, a, b);
//         }
//         if(root->data < a && root->data < b) {
//             return findDist(root->right, a, b);
//         }
//         return 0;
// }

// vector<Node*> findPreSuc(TreeNode* root, TreeNode* key){
//     vector<Node*> result(2, NULL); 
//     TreeNode* current = root;

//     while (current != NULL) {
//         if (key->data < current->data) {
//             result[1] = current; 
//             current = current->left;
//         } else if (key->data > current->data) {
//             result[0] = current; 
//             current = current->right;
//         } else {
//             if (current->left != NULL) {
//                 TreeNode* temp = current->left;
//                 while (temp->right != NULL) {
//                     temp = temp->right;
//                 }
//                 result[0] = temp; 
//             }
//             if (current->right != NULL) {
//                 TreeNode* temp = current->right;
//                 while (temp->left != NULL) {
//                     temp = temp->left;
//                 }
//                 result[1] = temp; 
//             }
//             break;
//         }
//     }

//     return result;
// }

// pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    
//     int predecessor = -1;
//     int successor = -1;

//     while (root != NULL) {
//         if (key < root->data) {
//             successor = root->data; 
//             root = root->left;
//         } else if (key > root->data) {
//             predecessor = root->data; 
//             root = root->right;
//         } else {
//             if (root->left != NULL) {
//                 TreeNode* temp = root->left;
//                 while (temp->right != NULL) {
//                     temp = temp->right;
//                 }
//                 predecessor = temp->data; 
//             }
//             if (root->right != NULL) {
//                 TreeNode* temp = root->right;
//                 while (temp->left != NULL) {
//                     temp = temp->left;
//                 }
//                 successor = temp->data; 
//             }
//             break;
//         }
//     }

//     return {predecessor, successor};
// }


// int main(){
//     TreeNode* root = new TreeNode(5);
//     root->left = new TreeNode(3);
//     root->right = new TreeNode(8);
//     root->left->left = new TreeNode(2);
//     root->left->right = new TreeNode(4);
//     root->right->left = new TreeNode(7);
//     root->right->right = new TreeNode(9);

//     TreeNode* p = root->left; // Node with value 3

//     TreeNode* successor = inorderSuccessor(root, p);
//     if (successor != NULL) {
//         cout << "Inorder Successor of " << p->data << ": " << successor->data << endl;
//     } else {
//         cout << "Inorder Successor of " << p->data << " does not exist." << endl;
//     }

//     TreeNode* predecessor = inorderPredecessor(root, p);
//     if (predecessor != NULL) {
//         cout << "Inorder Predecessor of " << p->data << ": " << predecessor->data << endl;
//     } else {
//         cout << "Inorder Predecessor of " << p->data << " does not exist." << endl;
//     }

//     return 0;
// }