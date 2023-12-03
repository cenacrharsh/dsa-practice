#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=FiFiNvM29ps&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47

/*
> Time Complexity: O(log2 (n))
> Space Complexity: O()
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Recursive
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);

        if (root == NULL)
        {
            root = newNode;
        }
        else if (val < root->val)
        {
            //* we know we have to go left
            if (root->left != NULL)
            {
                insertIntoBST(root->left, val);
            }
            else
            {
                root->left = newNode;
            }
        }
        else if (val > root->val)
        {
            //* we know we have to go right
            if (root->right != NULL)
            {
                insertIntoBST(root->right, val);
            }
            else
            {
                root->right = newNode;
            }
        }

        return root;
    }
};

//! Iterative
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }

        TreeNode *temp = root;
        while (true)
        {
            if (val < temp->val)
            {
                //* we have to move left
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                //* we have to move right
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};