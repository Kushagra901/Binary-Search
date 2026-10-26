/*
 * ======================================================================================
 * Problem: All Nodes Distance K in Binary Tree
 * Lecture: Lecture 30
 * Reference: LeetCode 863 - All Nodes Distance K in Binary Tree
 * 
 * Description:
 * Return an array of the values of all nodes that have a distance K from the target node in a binary tree.
 * 
 * Intuition & Approach:
 * First pass: Build parent pointers using a hash map `unordered_map<TreeNode*, TreeNode*>`. Second pass: Run radial BFS starting from target node in all 3 directions (left, right, parent) using a visited set until radial distance reaches K.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) | Space Complexity: O(N) for parent map, queue, and visited set
 * 
 * Similar / Related Problems:
 *   1. LeetCode 742 - Closest Leaf in a Binary Tree
 *   2. GFG - Burning Tree
 *   3. LeetCode 2385 - Amount of Time for Binary Tree to Be Infected
 * ======================================================================================
 */

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
    // Collects nodes exactly distance edges
    // below the given subtree root.
    void collectDown(
        TreeNode* node,
        int distance,
        vector<int>& answer
    ) {
        if (
            node == nullptr ||
            distance < 0
        ) {
            return;
        }

        if (distance == 0) {
            answer.push_back(node->val);
            return;
        }

        collectDown(
            node->left,
            distance - 1,
            answer
        );

        collectDown(
            node->right,
            distance - 1,
            answer
        );
    }

    // Returns the distance from node to target,
    // or -1 when target is absent from the subtree.
    int findTarget(
        TreeNode* node,
        TreeNode* target,
        int K,
        vector<int>& answer
    ) {
        if (node == nullptr) {
            return -1;
        }

        // Descendants exactly K levels below
        // target are collected immediately.
        if (node == target) {
            collectDown(
                node,
                K,
                answer
            );

            return 0;
        }

        int leftResult =
            findTarget(
                node->left,
                target,
                K,
                answer
            );

        if (leftResult != -1) {
            int currentDistance =
                leftResult + 1;

            // The ancestor itself is valid when
            // its distance from target equals K.
            if (currentDistance == K) {
                answer.push_back(node->val);
            } else {
                // The opposite subtree is searched for
                // nodes completing the remaining distance.
                collectDown(
                    node->right,
                    K - currentDistance - 1,
                    answer
                );
            }

            return currentDistance;
        }

        int rightResult =
            findTarget(
                node->right,
                target,
                K,
                answer
            );

        if (rightResult != -1) {
            int currentDistance =
                rightResult + 1;

            if (currentDistance == K) {
                answer.push_back(node->val);
            } else {
                // When target is on the right,
                // the left subtree becomes opposite.
                collectDown(
                    node->left,
                    K - currentDistance - 1,
                    answer
                );
            }

            return currentDistance;
        }

        return -1;
    }

public:
    // Finds nodes at distance K without
    // storing explicit parent relationships.
    vector<int> distanceK(
        TreeNode* root,
        TreeNode* target,
        int K
    ) {
        vector<int> answer;

        findTarget(
            root,
            target,
            K,
            answer
        );

        return answer;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;
    int K = 2;

    Solution solution;

    vector<int> answer =
        solution.distanceK(root, target, K);

    for (int value : answer) {
        cout << value << " ";
    }

    return 0;
}