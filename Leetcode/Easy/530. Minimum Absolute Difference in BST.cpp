#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=yNvt9ejf9Ec

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int minDiff = INT_MAX;
    TreeNode *prev;

    void helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left);

        if (prev != NULL)
        {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }

        prev = root;
        helper(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        prev = NULL;
        helper(root);
        return minDiff;
    }
};