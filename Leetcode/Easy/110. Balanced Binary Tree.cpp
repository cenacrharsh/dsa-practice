#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Yt50Jfbd8Po

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! DFS & passing height of tree uptill now

/*
> Time Complexity: O(N)
> Space Complexity: O(H)
*/

class Solution
{
public:
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSubtreeHeight = dfsHeight(root->left);
        if (leftSubtreeHeight == -1)
        {
            return -1;
        }

        int rightSubtreeHeight = dfsHeight(root->right);
        if (rightSubtreeHeight == -1)
        {
            return -1;
        }

        if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
        {
            return -1;
        }

        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        // return height of bst if balanced
        // return -1 if at any time not balanced
        return dfsHeight(root) != -1;
    }
};

//! Calc Height of Left & Right Subtree everytime

/*
> Time Complexity: O(N^2)
> Space Complexity: O(H)
*/

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSubtreeHeight = height(root->left);
        int rightSubtreeHeight = height(root->right);

        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int leftSubtreeHeight = height(root->left);
        int rightSubtreeHeight = height(root->right);

        if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
        {
            return false;
        }

        bool leftSubtree = isBalanced(root->left);
        bool rightSubtree = isBalanced(root->right);

        if (leftSubtree == false || rightSubtree == false)
        {
            return false;
        }

        return true;
    }
};