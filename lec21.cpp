/*
 * ======================================================================================
 * Problem: Vertical Order Traversal of Binary Tree
 * Lecture: Lecture 21
 * Reference: LeetCode 987 - Vertical Order Traversal of a Binary Tree
 * 
 * Description:
 * Traverse binary tree vertically column-by-column (from leftmost to rightmost vertical line). For overlapping nodes at same (x, y), sort by node value.
 * 
 * Intuition & Approach:
 * Assign 2D coordinate system: root at (vertical = 0, level = 0). Left child is at `(v - 1, l + 1)`, right is at `(v + 1, l + 1)`. Use BFS with a nested map `map<int, map<int, multiset<int>>>` to group and sort automatically.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N log N) due to map/multiset ordering | Space Complexity: O(N)
 * 
 * Similar / Related Problems:
 *   1. LeetCode 314 - Binary Tree Vertical Order Traversal
 *   2. LeetCode 199 - Binary Tree Right Side View
 *   3. GFG - Top View of Binary Tree
 * ======================================================================================
 */

//vertical order traversal of binary tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data=x;
        left=NULL;
        right=NULL; 
    }
};
vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left) todo.push({node->left, {x - 1, y + 1}});
        if(node->right) todo.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = verticalTraversal(root);
    for(const auto& col : result){
        for(int val : col){
            cout << val << " ";
        }
        cout << endl;
    }

}