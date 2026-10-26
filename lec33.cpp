/*
 * ======================================================================================
 * Problem: Requirements to Construct a Unique Binary Tree
 * Lecture: Lecture 33
 * Reference: Theory & Conceptual Foundation
 * 
 * Description:
 * Rules and conditions under which a unique binary tree can be constructed from traversal pairs.
 * 
 * Intuition & Approach:
 * To construct a unique binary tree, we MUST have Inorder traversal along with either Preorder or Postorder traversal. Inorder tells us what is in the left vs right subtree, while Preorder/Postorder identifies the root. Note: Preorder + Postorder does NOT guarantee a unique binary tree.
 * 
 * Complexity Analysis:
 * - Conceptual Lecture: Identifies why Inorder is strictly necessary for unique binary tree reconstruction.
 * 
 * Similar / Related Problems:
 *   1. LeetCode 105 - Construct Binary Tree from Preorder and Inorder
 *   2. LeetCode 106 - Construct Binary Tree from Inorder and Postorder
 *   3. LeetCode 889 - Construct Binary Tree from Preorder and Postorder
 * ======================================================================================
 */

// requ to constrcut a bt no code   