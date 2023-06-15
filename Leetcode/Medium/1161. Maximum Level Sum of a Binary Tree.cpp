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

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int maxSum = INT_MIN;
        int maxLevel = 1;
        int level = 1;
        queue<TreeNode *> nodesLeft;
        nodesLeft.push(root);

        while (!nodesLeft.empty())
        {
            int numNodesOnCurrLevel = nodesLeft.size();
            int levelSum = 0;
            while (numNodesOnCurrLevel--)
            {
                TreeNode *currNode = nodesLeft.front();
                nodesLeft.pop();
                levelSum += currNode->val;

                if (currNode->left != NULL)
                {
                    nodesLeft.push(currNode->left);
                }
                if (currNode->right != NULL)
                {
                    nodesLeft.push(currNode->right);
                }
            }

            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};