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

// # Tutorial: https://www.youtube.com/watch?v=6IFTcv5WZkA

/*
> Time Complexity: O(N * D^2)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int numOfGoodLeafPairs;
    vector<int> dfs(TreeNode *root, int distance)
    {
        if (root == NULL)
        {
            return {};
        }

        //* every leaf node return 1 to it's immediate parent
        if (root->left == NULL && root->right == NULL)
        {
            return {1};
        }

        vector<int> leftSubtreeVector = dfs(root->left, distance);
        vector<int> rightSubtreeVector = dfs(root->right, distance);

        //* now we'll see which leaf nodes can form a pair from all the leaf nodes received from both left and right subtrees
        for (auto leftSubtreeLeaf : leftSubtreeVector)
        {
            for (auto rightSubtreeLeaf : rightSubtreeVector)
            {
                if (leftSubtreeLeaf + rightSubtreeLeaf <= distance)
                {
                    numOfGoodLeafPairs++;
                }
            }
        }

        //* now we'll add +1 to each leaf and see if it's <= distance if yes we'll pass it forward
        vector<int> parentVector;
        for (auto leftSubtreeLeaf : leftSubtreeVector)
        {
            if (leftSubtreeLeaf + 1 < distance)
            {
                parentVector.push_back(leftSubtreeLeaf + 1);
            }
        }
        for (auto rightSubtreeLeaf : rightSubtreeVector)
        {
            if (rightSubtreeLeaf + 1 < distance)
            {
                parentVector.push_back(rightSubtreeLeaf + 1);
            }
        }

        return parentVector;
    }

    int countPairs(TreeNode *root, int distance)
    {
        //* each node will pass the distance to the leaf node to it's parent and from there we'll see how many pairs of good leaf node pairs are possible, so we'll return a vector containing distances to all leaf nodes connected to that node, for optimisation any time the distace becomes >= given distance we won't pass it forward because now it can be < distance in any case
        numOfGoodLeafPairs = 0;
        dfs(root, distance);
        return numOfGoodLeafPairs;
    }
};