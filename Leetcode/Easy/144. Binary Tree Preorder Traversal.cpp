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

//! Morris Traversal

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            //* 2 cases, left is NULL or it exists
            if (curr->left == NULL)
            {
                //* add root to inorder and move right, true for both inorder and preorder as left does'nt exist so root comes before right here as well
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                //* go to left subtree and find the last node of left subtree which will be visited in inorder of left subtree
                TreeNode *prev = curr->left;
                //* move as right as possible
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                //* prev is NULL or it points curr
                if (prev->right == NULL)
                {
                    prev->right = curr;            //* create thread
                    preorder.push_back(curr->val); //* we are visiting the root before moving to left
                    curr = curr->left;             //* normal traversal
                }
                else
                {
                    //* thread exists
                    prev->right = NULL; //* cut the thread
                    curr = curr->right; //* thread indicates left half has been visited
                }
            }
        }
        return preorder;
    }
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