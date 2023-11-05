#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=sWf7k1x9XR4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39

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
> Space Complexity: O(1)
*/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        //* the last node in left subtree if it exists a/q to preorder traversal will point to the first node in right subtree and the root will point to first node in left subtree since LL is to be in preorder (Root, Left, Right)

        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *prev = curr->left;
                while (prev->right != NULL)
                {
                    prev = prev->right; //* find the rightmost node in left subtree
                }
                prev->right = curr->right; //* connect last node in left subtree to first node in right subtree
                curr->right = curr->left;  //* connect root to first node in left subtree
                curr->left = NULL;
            }
            curr = curr->right; //* if no left subtree is present we simply move to next right node
        }
    }
};
