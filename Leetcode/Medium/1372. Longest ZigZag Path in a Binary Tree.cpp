#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=jdArJOUsIYg

/*
> Time Complexity: O(N)
> Space Complexity: O(Height of BT)
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLength = INT_MIN;
    void helper(TreeNode *root, int currDirection, int currLength)
    {
        if (root == NULL)
        {
            return;
        }

        maxLength = max(maxLength, currLength);

        // going to left, so dir becomes 0 and len is calc from prev dir, it is currLen + 1 if prev dir is right i.e. 1 else 1
        helper(root->left, 0, ((currDirection == 1) ? (currLength + 1) : 1));

        // going to right, so dir becomes 1 and len is calc from prev dir, it is currLen + 1 if prev dir is left i.e. 1 else 1
        helper(root->right, 1, ((currDirection == 0) ? (currLength + 1) : 1));
    }
    int longestZigZag(TreeNode *root)
    {
        // 0 -> coming from left, 1 -> coming from right
        // for root node we can assume it has both left & right parent
        helper(root, 0, 0);
        helper(root, 1, 0);

        return maxLength;
    }
};