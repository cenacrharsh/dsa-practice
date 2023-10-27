#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// # Tutorial: https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28

/*
> Time Complexity: O(N)
> Space Complexity: O(N) => auxiliary stack space
*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //* if either of the nodes is found return it
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        //* if either of left or right is not null value, return it
        //* if both are not null then we found our LCA so return the current node
        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};