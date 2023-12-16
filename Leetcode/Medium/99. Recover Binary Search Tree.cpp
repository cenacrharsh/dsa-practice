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

// # Tutorial: https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
    //* 2 cases: In the inorder traversal the 2 nodes are adjacent to each other or they are not, if adjacent the last would be null so we'll swap first and middle, but if not adjacent we'll swap first and last
private:
    TreeNode *first;
    TreeNode *last;
    TreeNode *prev;
    TreeNode *middle;

public:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            //* if this is first violation, then mark these 2 nodes are first and middle
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            //* if this is second violation, then mark current node as last
            else
            {
                last = root;
            }
        }
        //* mark this node as previous
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        //* 2 violations
        if (first && last)
        {
            swap(first->val, last->val);
        }
        //* one violation
        else
        {
            swap(first->val, middle->val);
        }
    }
};