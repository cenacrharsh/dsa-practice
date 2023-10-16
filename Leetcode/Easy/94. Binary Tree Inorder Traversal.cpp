#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Z_NEgBgbRVI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=7

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//- Left -> Root -> Right

//! Using Recursion

class Solution
{
public:
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        //* left
        helper(root->left, ans);

        //* root
        ans.push_back(root->val);

        //* right
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

//! Using Iteration

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> nodesLeft;
        TreeNode *currNode = root;

        while (currNode != NULL || !nodesLeft.empty())
        {
            // push all the left nodes of the currNode
            while (currNode != NULL)
            {
                nodesLeft.push(currNode);
                currNode = currNode->left;
            }

            // pop out the last pushed node from stack
            currNode = nodesLeft.top();
            nodesLeft.pop();
            ans.push_back(currNode->val);

            // now move to the right side of the currNode if there is any
            currNode = currNode->right;
        }
        return ans;
    }
};
