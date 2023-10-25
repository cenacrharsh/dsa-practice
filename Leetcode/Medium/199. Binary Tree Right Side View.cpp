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

// # Tutorial: https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=27

/*
> Time Complexity: O(N)
> Space Complexity: O(H)
*/

class Solution
{
public:
    void helper(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        //* eg. on level 0 we have 0 elements and on level 1 we have one element from level 0 and so on
        if (level == ans.size())
        {
            ans.push_back(root->val);
        }

        helper(root->right, level + 1, ans);
        helper(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        //* Recursive solution has better space complexity O(Height)
        //* We'll use Reverse Preorder Traversal (Root, Right, Left) as we want right side view so we want to visit right nodes first

        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};