/*
 * ======================================================================================
 * Problem: Representation of Binary Tree in C++
 * Lecture: Introduction / Representation
 * Reference: Fundamental Concept (Tree Node Definition)
 * 
 * Description:
 * Binary Tree node structure representation in C++ using struct/class with data, left, and right pointers, and creating root and children dynamically.
 * 
 * Intuition & Approach:
 * A binary tree is a non-linear hierarchical data structure where each node has at most two children (left child and right child). In C++, it is represented using a `struct` or `class` containing the node value and two self-referential pointers (`left` and `right`).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(1) to create a node | Space Complexity: O(1) auxiliary space per node
 * 
 * Similar / Related Problems:
 *   1. LeetCode 226 - Invert Binary Tree
 *   2. LeetCode 104 - Maximum Depth of Binary Tree
 *   3. GFG - Binary Tree Node Representation
 * ======================================================================================
 */

//reresent tree in c++
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL; 
    }
};


int main(){ 
    struct Node* root = new struct Node(1);
    root->left = new struct Node(2);
    root->right = new struct Node(3);
}