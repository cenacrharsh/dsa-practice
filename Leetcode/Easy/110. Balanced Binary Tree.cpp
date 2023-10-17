#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=16

/*
> Time Complexity: O(N)
> Space Complexity: O(N) => auxiliary stack space
*/

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
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
        {
            return -1;
        }

        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
        {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        if (dfsHeight(root) != -1)
        {
            return true;
        }
        return false;
    }
};
