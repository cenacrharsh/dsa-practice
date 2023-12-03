#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=kouxiP_H5WE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=45

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
    TreeNode *findLastRight(TreeNode *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return findLastRight(root->right);
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild; //* connect the right subtree to the maximum value in left subtree
        return root->left;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (key < curr->val)
            {
                if (curr->left != NULL && curr->left->val == key)
                {
                    curr->left = helper(curr->left);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->right != NULL && curr->right->val == key)
                {
                    curr->right = helper(curr->right);
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};