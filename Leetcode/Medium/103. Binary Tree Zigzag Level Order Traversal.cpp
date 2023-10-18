#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https: // www.youtube.com/watch?v=3OXWEdlIGl4

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
    vector<vector<int>>
    zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> nodesLeft;
        nodesLeft.push(root);
        bool leftToRight = true;

        while (!nodesLeft.empty())
        {
            int sizeOfCurrLevel = nodesLeft.size();
            vector<int> currLevel(sizeOfCurrLevel);

            for (int i = 0; i < sizeOfCurrLevel; i++)
            {
                TreeNode *currNode = nodesLeft.front();
                nodesLeft.pop();

                //* depending on flag we either insert from front or back
                int index = leftToRight ? i : sizeOfCurrLevel - 1 - i;
                currLevel[index] = currNode->val;

                if (currNode->left != NULL)
                {
                    nodesLeft.push(currNode->left);
                }
                if (currNode->right != NULL)
                {
                    nodesLeft.push(currNode->right);
                }
            }
            //* reverse the direction of traversal
            leftToRight = !leftToRight;

            ans.push_back(currLevel);
        }
        return ans;
    }
};