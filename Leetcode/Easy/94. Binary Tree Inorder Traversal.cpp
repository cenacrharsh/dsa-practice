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

//! Using Morris Traversal

/*
> Time Complexity: O(N) => Amotized
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            //* 2 cases, left is NULL or it exists
            if (curr->left == NULL)
            {
                //* add root to inorder and move right
                inorder.push_back(curr->val);
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
                    prev->right = curr; //* create thread
                    curr = curr->left;  //* normal traversal
                }
                else
                {
                    //* thread exists
                    prev->right = NULL;           //* cut the thread
                    inorder.push_back(curr->val); //* we are visiting the root after visiting the left subtree
                    curr = curr->right;           //* thread indicates left half has been visited
                }
            }
        }
        return inorder;
    }
};

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

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    //* Root->Left->Right
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == NULL)
        {
            return preorder;
        }

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *currNode = st.top();
            st.pop();

            preorder.push_back(currNode->val);

            if (currNode->right != NULL)
            {
                st.push(currNode->right);
            }
            if (currNode->left != NULL)
            {
                st.push(currNode->left);
            }
        }
        return preorder;
    }
};