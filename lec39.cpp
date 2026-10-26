/*
 * ======================================================================================
 * Problem: Introduction to Binary Search Tree (BST)
 * Lecture: Lecture 39
 * Reference: BST Fundamentals & Properties
 * 
 * Description:
 * Core definition, properties, and ordering invariants of Binary Search Trees.
 * 
 * Intuition & Approach:
 * For every node X in a BST: all values in the left subtree are strictly less than X, and all values in the right subtree are strictly greater than X. Inorder traversal of any BST always produces a strictly sorted sequence in ascending order.
 * 
 * Complexity Analysis:
 * - Search/Insert/Delete: O(log N) average, O(N) worst case (skewed tree)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 700 - Search in a Binary Search Tree
 *   2. LeetCode 98 - Validate Binary Search Tree
 *   3. LeetCode 701 - Insert into a Binary Search Tree
 * ======================================================================================
 */

//intro to binary search tree