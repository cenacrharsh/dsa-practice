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

// # Tutorial: https://www.youtube.com/watch?v=vnoIf46JtAo

class Solution
{
public:
    void helper(TreeNode *root, vector<int> &freq, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        //* increase freq in vector
        freq[root->val]++;

        helper(root->left, freq, count);
        helper(root->right, freq, count);

        //* if leaf node is reached we check pallindromic path or not
        if (root->left == NULL && root->right == NULL)
        {
            //* in pallindromic seq we can have at max one odd freq
            int oddFreqCount = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (freq[i] % 2 != 0)
                {
                    oddFreqCount++;
                }
            }
            if (oddFreqCount == 0 || oddFreqCount == 1)
            {
                count++;
            }
        }

        //* backtrack and remove current node from freq
        freq[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        int count = 0;
        vector<int> freq(10, 0);
        helper(root, freq, count);
        return count;
    }
};