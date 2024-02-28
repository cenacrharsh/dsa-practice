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

// # Tutorial: https://www.youtube.com/watch?v=Rezetez59Nk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=17

/*
> Time Complexity: O(N)
> Space Complexity: O(N) => auxiliary stack space
*/

//- Diameter of a BT: longest path between 2 nodes of a binary tree, and the path need not path through the root

//- for a given node the max length of path that goes through it is leftHeight + rightHeight

class Solution
{
public:
    //* by height we mean distance b/w nodes, for eg. 1->2->3->4->5 => height = 4 from node 1
    int dfsHeight(TreeNode *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = dfsHeight(root->left, diameter);
        int rightHeight = dfsHeight(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight); //* if a node x has lh = 2, rh = 3 then for the node above it it's height is going to be 1 + max(2,3) = 4
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }
};