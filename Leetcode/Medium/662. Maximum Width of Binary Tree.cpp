#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZbybYvcVLks

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        //* width: no. of nodes in a level b/w any 2 nodes
        //* if root is i -> left: 2i + 1, right: 2i + 2
        if (root == NULL)
        {
            return 0;
        }
        int maxWidth = 0;
        queue<pair<TreeNode *, int>> nodesLeft;
        nodesLeft.push({root, 0});
        while (!nodesLeft.empty())
        {
            int size = nodesLeft.size();
            int minIndex = nodesLeft.front().second; //* to make id start from 0 in each level and prevent overflow
            int first, last;
            for (int i = 0; i < size; i++)
            {
                int curr_id = nodesLeft.front().second - minIndex;
                TreeNode *currNode = nodesLeft.front().first;
                nodesLeft.pop();

                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;

                if (currNode->left != NULL)
                {
                    nodesLeft.push({currNode->left, (long long)2 * curr_id + 1});
                }
                if (currNode->right != NULL)
                {
                    nodesLeft.push({currNode->right, (long long)2 * curr_id + 2});
                }
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};