#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=9

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> nodesLeft;
        nodesLeft.push(root);

        while (!(nodesLeft.empty()))
        {
            int numOfNodesInCurrLevel = nodesLeft.size();
            vector<int> temp;

            while (numOfNodesInCurrLevel--)
            {
                TreeNode *currNode = nodesLeft.front();
                nodesLeft.pop();
                temp.push_back(currNode->val);

                if (currNode->left != NULL)
                {
                    nodesLeft.push(currNode->left);
                }
                if (currNode->right != NULL)
                {
                    nodesLeft.push(currNode->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};