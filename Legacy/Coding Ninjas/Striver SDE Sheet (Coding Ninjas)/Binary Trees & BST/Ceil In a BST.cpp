#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=KSsk8AhdOZA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=42

//* ceil of n => lowest value >= n

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findCeil(TreeNode *root, int key)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (root->val == key)
        {
            return root->val;
        }

        if (root->val < key)
        {
            root = root->right;
        }
        else
        {
            //* root->val > key
            ceil = root->val;
            root = root->left; //* try to find lower values if possible
        }
    }

    return ceil;
}