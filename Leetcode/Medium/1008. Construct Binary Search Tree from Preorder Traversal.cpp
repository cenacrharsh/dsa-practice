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

// # Tutorial: https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=49

/*
> Time Complexity: O(3N) ~ O(N)
> Space Complexity: O(N) => recursive stack space
*/

class Solution
{
public:
    TreeNode *helper(vector<int> &preorder, int &i, int upperBound)
    {
        //* if no elements left or if we cross upper bound
        if (i == preorder.size() || preorder[i] > upperBound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, upperBound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};