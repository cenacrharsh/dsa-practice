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

// # Tutorial: https://www.youtube.com/watch?v=9Aw18-yQs6o

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    /*
    Inorder traverse of BST will give an ascending sequence of all values.
    By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree,
    we can get the descending order of the BST.
    That is, before encoutering the current node, we have exactly visited all the values that greater than it.
    So we just need to set a variable(cur_sum) to keep track the summation of the visited nodes.
    */

    int globalSum;
    void helper(TreeNode* node, int &globalSum) {
        if(node == NULL) {
            return;
        }

        helper(node->right, globalSum);

        globalSum += node->val;
        node->val = globalSum;

        helper(node->left, globalSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        globalSum = 0;
        helper(root, globalSum);
        return root;
    }
};