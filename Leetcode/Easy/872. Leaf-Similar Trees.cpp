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

class Solution
{
public:
    void leaf(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            leaf(root->left, ans);
        }
        if (root->right != NULL)
        {
            leaf(root->right, ans);
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> treeLeaf1;
        leaf(root1, treeLeaf1);

        vector<int> treeLeaf2;
        leaf(root2, treeLeaf2);

        if (treeLeaf1 == treeLeaf2)
        {
            return true;
        }
        return false;
    }
};