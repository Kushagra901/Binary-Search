/*
 * ======================================================================================
 * Problem: Children Sum Property in Binary Tree
 * Lecture: Lecture 29
 * Reference: GFG / Coding Ninjas - Children Sum Property
 * 
 * Description:
 * Convert an arbitrary binary tree into one that satisfies the Children Sum Property (node->data = left->data + right->data) by only incrementing node values.
 * 
 * Intuition & Approach:
 * Top-down: ensure parent value is propagated down if children sum is smaller. Bottom-up: after children subtrees satisfy the property, update parent to exact sum of updated left and right children.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion stack
 * 
 * Similar / Related Problems:
 *   1. LeetCode 129 - Sum Root to Leaf Numbers
 *   2. GFG - Check for Children Sum Property
 *   3. LeetCode 112 - Path Sum
 * ======================================================================================
 */

// //children sum in binary tree
// #include <bits/stdc++.h>
// using namespace std;

// // bool isSumProperty(Node *root) {
// //         if (root == NULL) {
// //             return true;
// //         }
// //         int child = 0;
// //         if(root->left){
// //             child += root->left->data;
// //         } 
// //         if(root->right){
// //             child += root->right->data;
// //         }
// //         if(child >= root->data) root->data = child;
// //         else{
// //             if(root->left) root->left->data = root->data;
// //             else if(root->right) root->right->data = root->data;    
// //         }
// //         reorder(root->left);
// //         reorder(root->right);
// //         int tot = 0;
// //         if(root->left) tot += root->left->data;
// //         if(root->right) tot += root->right->data;
// //         if(root->left or root->right) root->data = tot;
// //     }
// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     Node(int x){
//         data=x;
//         left=NULL;
//         right=NULL; 
//     }
// };
// void changeTree(BinaryTreeNode < int > * root) {
//     if (root == NULL) {
//         return;
//     }
//     int child = 0;
//     if (root -> left != NULL) {
//         child += root -> left -> data;
//     }
//     if (root -> right != NULL) {
//         child += root -> right -> data;
//     }
//     if (child >= root -> data) {
//         root -> data = child;
//     } else {
//         if (root -> left != NULL) {
//             root -> left -> data = root -> data;
//         } else if (root -> right != NULL) {
//             root -> right -> data = root -> data;
//         }
//     }
//     changeTree(root -> left);
//     changeTree(root -> right);
//     int tot = 0;
//     if (root -> left != NULL) {
//         tot += root -> left -> data;
//     }
//     if (root -> right != NULL) {
//         tot += root -> right -> data;
//     }
//     if (root -> left != NULL || root -> right != NULL) {
//         root -> data = tot;
//     }
// }  

// int main(){
//     Node* root=new Node(10);
//     root->left=new Node(8);
//     root->right=new Node(2);
//     root->left->left=new Node(3);
//     root->left->right=new Node(5);
//     root->right->right=new Node(2);
//     changeTree(root);
//     if(isSumProperty(root)){
//         cout<<"The tree satisfies the children sum property"<<endl;
//     } else {
//         cout<<"The tree does not satisfy the children sum property"<<endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL; 
    }
};
bool isSumProperty(Node *root) {
        if (root == NULL) {
            return true;
        }
        int child = 0;
        if(root->left){
            child += root->left->data;
        } 
        if(root->right){
            child += root->right->data;
        }
        if(child >= root->data) root->data = child;
        else{
            if(root->left) root->left->data = root->data;
            else if(root->right) root->right->data = root->data;    
        }
        int tot = 0;
        if(root->left) tot += root->left->data;
        if(root->right) tot += root->right->data;
        if(root->left or root->right) root->data = tot;
    }

int main(){
    Node* root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(5);
    root->right->right=new Node(2);
    isSumProperty(root);
    if(isSumProperty(root)){
        cout<<"The tree satisfies the children sum property"<<endl;
    } else {
        cout<<"The tree does not satisfy the children sum property"<<endl;
    }
    return 0;
}