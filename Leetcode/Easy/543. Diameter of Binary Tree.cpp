#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    /**
     * This function returns the number of NODES on the longest path down to a leaf.
     * Example: 1->2->3 returns 3.
     */
    int dfsHeight(TreeNode *root, int &diameter)
    {
        if (root == NULL)
        {
            // Base case: A null tree has 0 nodes.
            return 0;
        }

        // Recursively find the max nodes in left and right subtrees
        int leftNodes = dfsHeight(root->left, diameter);
        int rightNodes = dfsHeight(root->right, diameter);

        /**
         * DIAMETER LOGIC:
         * The number of edges passing through this node is (leftNodes + rightNodes).
         * Since leftNodes and rightNodes are counts, their sum naturally represents
         * the total number of edges connecting those two paths.
         */
        diameter = max(diameter, leftNodes + rightNodes);

        // Return the number of nodes in the longest path including this current node
        return 1 + max(leftNodes, rightNodes);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }
};
