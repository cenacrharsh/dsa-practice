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