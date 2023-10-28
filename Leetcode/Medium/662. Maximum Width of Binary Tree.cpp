#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

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
        //* root = i, left child = (2 * i) + 1, right child = (2 * i) + 2
        //* to prevent overflow we'll take (i - min on that level) instead of i
        //* width = max distance b/w any 2 nodes on a level, using formula (max - min + 1)  on any level

        if (root == NULL)
        {
            return 0;
        }

        int ans = 0;
        queue<pair<TreeNode *, int>> q; //* (node, index)
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int minIndex = q.front().second; //* to make id start from 0 in each level and prevent overflow
            int first, last;
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front().first;
                int currIndex = q.front().second - minIndex;
                q.pop();

                if (i == 0)
                {
                    first = currIndex;
                }
                if (i == size - 1)
                {
                    last = currIndex;
                }

                if (currNode->left != NULL)
                {
                    q.push({currNode->left, (long long)2 * currIndex + 1});
                }
                if (currNode->right != NULL)
                {
                    q.push({currNode->right, (long long)2 * currIndex + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};