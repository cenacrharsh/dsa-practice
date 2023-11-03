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

// # Tutorial: https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35

/*
> Time Complexity: O(N) + time to insert in map
> Space Complexity: O(N) + stack space for recursion
*/

class Solution
{
public:
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);

        //* find index of root element in inorder
        int inRoot = inorderMap[root->val];

        //* find no. of elements to the left of root
        int numLeft = inRoot - inStart;

        root->left = helper(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inorderMap);
        root->right = helper(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorderMap; //* (node, position)
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        TreeNode *root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);

        return root;
    }
};