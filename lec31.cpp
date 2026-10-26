/*
 * ======================================================================================
 * Problem: Minimum Time Taken to BURN / Infect the Binary Tree
 * Lecture: Lecture 31
 * Reference: LeetCode 2385 - Amount of Time for Binary Tree to Be Infected / GFG Burning Tree
 * 
 * Description:
 * Find the minimum time required to burn the entire binary tree if fire starts from a given target node and spreads to adjacent nodes (parent, left, right) in 1 second.
 * 
 * Intuition & Approach:
 * Map parents with BFS/DFS. Then execute BFS outward from start node simultaneously infecting parent, left, and right neighbors. Number of BFS expansion levels equals minimum burn time.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(N)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 863 - All Nodes Distance K in Binary Tree
 *   2. LeetCode 994 - Rotting Oranges
 *   3. GFG - Burning Tree
 * ======================================================================================
 */

//min time to burn a bt
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
private:
    struct Info {
        int height;
        int distanceFromTarget;
    };

    // Returns subtree height and the distance
    // from the current node to the target.
    Info dfs(
        TreeNode* node,
        TreeNode* target,
        int& maxTime
    ) {
        if (node == nullptr) {
            return {-1, -1};
        }

        Info left =
            dfs(node->left, target, maxTime);

        Info right =
            dfs(node->right, target, maxTime);

        int height =
            1 + max(left.height, right.height);

        // When target is reached, its subtree
        // height gives the farthest downward burn.
        if (node == target) {
            maxTime = max(
                maxTime,
                height
            );

            return {height, 0};
        }

        if (left.distanceFromTarget != -1) {
            int distanceFromTarget =
                left.distanceFromTarget + 1;

            // The route moves from target to this
            // ancestor, then one edge into the
            // opposite subtree and to its deepest node.
            maxTime = max(
                maxTime,
                distanceFromTarget
                + 1
                + right.height
            );

            return {
                height,
                distanceFromTarget
            };
        }

        if (right.distanceFromTarget != -1) {
            int distanceFromTarget =
                right.distanceFromTarget + 1;

            // The left subtree is the opposite
            // branch when target lies on the right.
            maxTime = max(
                maxTime,
                distanceFromTarget
                + 1
                + left.height
            );

            return {
                height,
                distanceFromTarget
            };
        }

        return {height, -1};
    }

public:
    // Finds the maximum distance from target
    // without storing explicit parent links.
    int minTime(
        TreeNode* root,
        TreeNode* target
    ) {
        if (root == nullptr) {
            return 0;
        }

        int maxTime = 0;

        dfs(
            root,
            target,
            maxTime
        );

        return maxTime;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode* target = root->left;

    Solution solution;

    cout << solution.minTime(root, target) << endl;

    return 0;
}