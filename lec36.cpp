/*
 * ======================================================================================
 * Problem: Serialize and Deserialize Binary Tree
 * Lecture: Lecture 36
 * Reference: LeetCode 297 - Serialize and Deserialize Binary Tree
 * 
 * Description:
 * Design an algorithm to serialize a binary tree to a string and deserialize that string back to the original binary tree.
 * 
 * Intuition & Approach:
 * Use Level Order Traversal (BFS). Serialize: append node values separated by commas, using '#' for NULL. Deserialize: parse comma-separated tokens with `stringstream`, construct root, and use a queue to link children level by level.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N) for both serialize and deserialize | Space Complexity: O(N)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 449 - Serialize and Deserialize BST
 *   2. LeetCode 428 - Serialize and Deserialize N-ary Tree
 *   3. LeetCode 652 - Find Duplicate Subtrees
 * ======================================================================================
 */

//serialize and deserialize a binary tree
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

string serialize(TreeNode* root) {
    if (!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curNode = q.front();
        q.pop();
        if(curNode == NULL){
            s.append("#,");
            } else {
                s.append(to_string(curNode->val) + ',');
            }
            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        cout << s;
        return s;
}
TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#"){
            node->left = NULL;
        } else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if(str == "#"){
            node->right = NULL;
        } else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized: ";
    serialize(deserialized);

    return 0;
}