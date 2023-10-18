#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
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
    int helper(TreeNode *root, int &maxSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSum = max(0, helper(root->left, maxSum));
        int rightSum = max(0, helper(root->right, maxSum));

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        //* return the path (left or right) which will give maximum sum from the current node
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode *root)
    {
        //* on every node we return the maximum path (i.e from that node we should go left or right), and maintain a variable to calculate the longest path
        //* we ignore the negative path sums to maximize the sum

        int maxSum = INT_MIN; //* if only one node exists with a negative value then path sum is also negative so initial value can't be 0
        helper(root, maxSum);
        return maxSum;
    }
};