#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// # Tutorial: https://www.youtube.com/watch?v=tZ3tUOrB790

//! Backtracking

/*
> Time Complexity: O(N + N)
> Space Complexity: O(1)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int startValue, int destValue) {
        //* if either of the nodes is found return it
        if(root == NULL || root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, startValue, destValue);
        TreeNode* right = lowestCommonAncestor(root->right, startValue, destValue);

        //* if either of left or right is not null value, return it
        //* if both are not null then we found our LCA so return the current node
        if(left == NULL) {
            return right;
        } else if(right == NULL) {
            return left;
        } else {
            return root;
        }
    }

    string lcaToStartValue, lcaToDestValue;
    void dfs(TreeNode* node, string& pathString, int startValue, int destValue) {
        if(node == NULL) {
            return;
        }

        if(node->val == startValue) {
            lcaToStartValue = pathString;
        }
        if(node->val == destValue) {
            lcaToDestValue = pathString;
        }

        //* backtracking to try all paths
        pathString.push_back('L');
        dfs(node->left, pathString, startValue, destValue);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(node->right, pathString, startValue, destValue);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        //* shortest path from startValue to destValue is via LCA of startValue and destValue
        TreeNode* lcaNode = lowestCommonAncestor(root, startValue, destValue);

        string pathString = "";
        dfs(lcaNode, pathString, startValue, destValue);

        for(auto& ch : lcaToStartValue) {
            ch = 'U';
        }
        return lcaToStartValue + lcaToDestValue;
    }
};