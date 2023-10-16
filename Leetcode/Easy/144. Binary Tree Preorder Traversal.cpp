#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=COQOU6klsBg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=8

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Using Recursion

/*
> Time Complexity: O(n)
> Space Complexity: O(n) => auxiliary stack space
*/

class Solution
{
public:
    /*
    - Root -> Left -> Right
    In a preorder traversal, we need to visit the root node first, then all left child nodes, followed by the right child nodes.
    */
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        //* root node
        ans.push_back(root->val);

        //* left node
        helper(root->left, ans);

        //* right node
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

//! Using Iteration

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    //* Left->Root->Right
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        if (root == NULL)
        {
            return inorder;
        }

        stack<TreeNode *> st;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left; //* Left
            }
            else
            {
                if (st.empty())
                {
                    break;
                }

                node = st.top();
                st.pop();

                inorder.push_back(node->val); //* Root
                node = node->right;           //* Right
            }
        }
        return inorder;
    }
};