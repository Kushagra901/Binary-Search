/*
 * ======================================================================================
 * Problem: Iterative Preorder Traversal of Binary Tree
 * Lecture: Lecture 9
 * Reference: LeetCode 144 - Binary Tree Preorder Traversal (Iterative)
 * 
 * Description:
 * Traverse binary tree in preorder (Root -> Left -> Right) iteratively using an explicit stack.
 * 
 * Intuition & Approach:
 * Use a stack. Push root. While stack is not empty, pop top node, visit it, then push its right child first, and left child second (so left is popped and visited before right due to LIFO property).
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(H) stack space
 * 
 * Similar / Related Problems:
 *   1. LeetCode 94 - Binary Tree Inorder Traversal (Iterative)
 *   2. LeetCode 145 - Binary Tree Postorder Traversal (Iterative)
 *   3. LeetCode 173 - Binary Search Tree Iterator
 * ======================================================================================
 */

//iterative traversal of binary tree
// #include <bits/stdc++.h>
// using namespace std;



// int main(){

// }
//same as lecture 5
