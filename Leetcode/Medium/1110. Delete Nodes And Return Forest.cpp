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

// # Tutorial: https://www.youtube.com/watch?v=FQ7HuXTM-KA

class Solution
{
public:
    vector<TreeNode *> ans;
    void dfs(TreeNode *node, unordered_set<int> &toBeDeletedNodes, bool isRootNode)
    {
        if (node == NULL)
        {
            return;
        }

        //* check if current node is marked to be deleted
        if (toBeDeletedNodes.find(node->val) != toBeDeletedNodes.end())
        {
            //* since node is to be deleted it's children become root nodes
            dfs(node->left, toBeDeletedNodes, true);
            dfs(node->right, toBeDeletedNodes, true);
        }
        else
        {
            //* check if current node was root node, if yes and since it reached here means it's not marked to be deleted hence store it in our ans
            if (isRootNode)
            {
                ans.push_back(node);
            }

            TreeNode *leftNode = node->left;
            TreeNode *rightNode = node->right;

            if (node->left)
            {
                if (toBeDeletedNodes.find(node->left->val) != toBeDeletedNodes.end())
                {
                    node->left = NULL;
                }
            }

            if (node->right)
            {
                if (toBeDeletedNodes.find(node->right->val) != toBeDeletedNodes.end())
                {
                    node->right = NULL;
                }
            }

            //* we marked leftNode and rightNode as NULL if there were to be deleted but we still need to call dfs on them hence we preserved their value beforehand
            dfs(leftNode, toBeDeletedNodes, false);
            dfs(rightNode, toBeDeletedNodes, false);
        }
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        ans.clear();
        unordered_set<int> toBeDeletedNodes(to_delete.begin(), to_delete.end());

        //* once parent node is deleted it's children become a root node in themselves hence we have to maintain which nodes are root nodes and which are not
        dfs(root, toBeDeletedNodes, true);

        return ans;
    }
};