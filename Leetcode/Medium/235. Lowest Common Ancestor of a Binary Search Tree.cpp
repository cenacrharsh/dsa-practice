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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// # Tutorial: https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52

//! BST Approach

/*
> Time Complexity: O(H)
> Space Complexity: O(n) => auxiliary stack space
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //* if both nodes lie on left wo move left, if both lie on right we move right but if neither case then it means one node is in left and one right or the root itself is one of the nodes and in either case we have found the LCA
        if (root == NULL)
        {
            return NULL;
        }
        //* check if both nodes lie on left or right
        if ((p->val < root->val) && (q->val < root->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if ((p->val > root->val) && (q->val > root->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

//! Binary Tree Approach

/*
> Time Complexity: O(n)
> Space Complexity: O(n) => auxiliary stack space
*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

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
            //* both left and right are not null, we found our result
            return root;
        }
    }
};