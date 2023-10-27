#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// # Tutorial: https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

//! Using Preorder Traversal
void helper(Node *root, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }

    temp.push_back(root->data);

    //* if it's a leaf node we push it's path inside ans
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
    }

    helper(root->left, temp, ans);
    helper(root->right, temp, ans);
    // temp.pop_back(); //* since we not passing temp as reference, we don't have to pop the element before passing
}

vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    vector<int> temp;
    helper(root, temp, ans);
}