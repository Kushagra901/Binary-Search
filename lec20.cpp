/*
 * ======================================================================================
 * Problem: Boundary Traversal of Binary Tree
 * Lecture: Lecture 20
 * Reference: GFG / LeetCode 545 - Boundary of Binary Tree
 * 
 * Description:
 * Perform an anti-clockwise boundary traversal: Root -> Left Boundary (excluding leaves) -> Leaf Nodes (left-to-right) -> Right Boundary (bottom-up, excluding leaves).
 * 
 * Intuition & Approach:
 * Divide into 3 modular tasks: (1) Add left boundary nodes ignoring leaf nodes; (2) Inorder/preorder to collect all leaf nodes; (3) Collect right boundary nodes bottom-up using a temporary vector / stack (ignoring leaves).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) recursion/stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 199 - Binary Tree Right Side View
 *   2. GFG - Diagonal Traversal of Binary Tree
 *   3. LeetCode 103 - Binary Tree Zigzag Traversal
 * ======================================================================================
 */

//bundary traversal of binary tree
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
 bool isLeaf(Node* node) {
    return !node->left && !node->right;
}
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}
void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}
void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = boundaryTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}