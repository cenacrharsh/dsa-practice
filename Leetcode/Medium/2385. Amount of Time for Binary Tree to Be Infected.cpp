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

// # Tutorial: https://www.youtube.com/watch?v=2r5wLmQfD6g

/*
> Time Complexity: O(N) + O(N) ~ O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int findMaxTime(unordered_map<TreeNode *, TreeNode *> &um, TreeNode *target)
    {
        queue<TreeNode *> nodesLeft;
        nodesLeft.push(target);

        unordered_map<TreeNode *, int> visited;
        visited[target] = 1;

        int maxTime = 0;
        while (!nodesLeft.empty())
        {
            int size = nodesLeft.size();
            bool burned = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = nodesLeft.front();
                nodesLeft.pop();

                // left child
                if (currNode->left && visited[currNode->left] == 0)
                {
                    visited[currNode->left] = 1;
                    nodesLeft.push(currNode->left);
                    burned = true;
                }

                // right child
                if (currNode->right && visited[currNode->right] == 0)
                {
                    visited[currNode->right] = 1;
                    nodesLeft.push(currNode->right);
                    burned = true;
                }

                // parent
                if (um[currNode] && visited[um[currNode]] == 0)
                {
                    visited[um[currNode]] = 1;
                    nodesLeft.push(um[currNode]);
                    burned = true;
                }
            }
            //* if burned is true then adjacent node was burned
            if (burned)
            {
                maxTime++;
            }
        }
        return maxTime;
    }

    TreeNode *bfsToMapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &um, int start)
    {
        queue<TreeNode *> nodesLeft;
        nodesLeft.push(root);
        TreeNode *res;
        while (!nodesLeft.empty())
        {
            TreeNode *currNode = nodesLeft.front();
            nodesLeft.pop();

            if (currNode->val == start)
            {
                res = currNode;
            }

            if (currNode->left)
            {
                um[currNode->left] = currNode;
                nodesLeft.push(currNode->left);
            }
            if (currNode->right)
            {
                um[currNode->right] = currNode;
                nodesLeft.push(currNode->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> um;
        TreeNode *target = bfsToMapParents(root, um, start);
        return findMaxTime(um, target);
    }
};