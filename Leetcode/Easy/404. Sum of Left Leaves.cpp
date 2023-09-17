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

//! Iterative
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftLeafSum = 0;
        stack<TreeNode *> treeNodes;
        treeNodes.push(root);
        while (!treeNodes.empty())
        {
            TreeNode *currNode = treeNodes.top();
            treeNodes.pop();
            if (currNode->left != NULL)
            {
                if (currNode->left->left == NULL && currNode->left->right == NULL)
                {
                    leftLeafSum += currNode->left->val;
                }
                else
                {
                    treeNodes.push(currNode->left);
                }
            }
            if (currNode->right != NULL)
            {
                treeNodes.push(currNode->right);
            }
        }
        return leftLeafSum;
    }
};

//! Recursive DFS
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftLeafSum = 0;
        if (root->left != NULL)
        {
            if (root->left->left == NULL && root->left->right == NULL)
            {
                leftLeafSum += root->left->val;
            }
            else
            {
                leftLeafSum += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right != NULL)
        {
            sumOfLeftLeaves(root->right);
        }
        return leftLeafSum;
    }
};