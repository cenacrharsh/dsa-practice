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

// # Tutorial: https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

/*
> Time Complexity: O(log N) * O(log N) => log N for traversing (max traversals if skew tree then log N) * log N to find of the subtree
> Space Complexity: O(log N) => recursion can go upto max log N
*/

class Solution
{
public:
    /*
        -🍇 Formula is (2^TreeLevel - 1). Only works for perfect tree.
        -🍇 To determine if its a perfect tree, go all the way down and count the nodes on left and right side, If they match, its a perfect tree and our formula applies.
        -🍇 If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
        -🍇 When we have our left and right heights, we do (1 + left + right)
        -🍇 If we reach null, return 0
        -🍇 C++ note: 1 << n is the same as raising 2 to the power n, or 2^n
    */

    int findLeftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        //* check for perfect binary tree
        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1; //* max no. of nodes in perfect binary tree of height h
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};