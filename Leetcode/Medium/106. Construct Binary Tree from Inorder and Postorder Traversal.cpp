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

// # Tutorial: https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36

/*
> Time Complexity: O(N) + time to insert in map
> Space Complexity: O(N) + stack space for recursion
*/

class Solution
{
public:
    TreeNode *helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inorderMap)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);

        //* find position of root in inorder
        int inRoot = inorderMap[root->val];

        //* find no. of elements to the left
        int numLeft = inRoot - inStart;

        root->left = helper(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numLeft - 1, inorderMap);
        root->right = helper(inorder, inRoot + 1, inEnd, postorder, postStart + numLeft, postEnd - 1, inorderMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorderMap; //* (node, position)
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        TreeNode *root = helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);

        return root;
    }
};