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

// # Tutorial: https://www.youtube.com/watch?v=u_by_cTsNJA

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        //* if we traverse from level wise from right to left, the last node we'll touch is out answer
        queue<TreeNode *> nodesLeft;
        nodesLeft.push(root);
        TreeNode *ans;
        while (!nodesLeft.empty())
        {
            int levelSize = nodesLeft.size();
            while (levelSize--)
            {
                ans = nodesLeft.front();
                nodesLeft.pop();
                //* for traversing right to left, we'll push right child first
                if (ans->right)
                {
                    nodesLeft.push(ans->right);
                }
                if (ans->left)
                {
                    nodesLeft.push(ans->left);
                }
            }
        }
        return ans->val;
    }
};