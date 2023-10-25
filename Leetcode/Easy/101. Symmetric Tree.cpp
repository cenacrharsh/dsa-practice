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

// # Tutorial: https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return left == right; //* if either is null both should be null else false
        }

        if (left->val != right->val)
        {
            return false;
        }

        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        //* left children of left subtree == right children of right subtree
        //* right children of left subtree == left children of left subtree

        if (root == NULL)
        {
            return false;
        }

        return helper(root->left, root->right);
    }
};