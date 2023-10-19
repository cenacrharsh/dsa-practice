#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=0ca1nvR0be4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=22

/*
> Time Complexity: O(H) + O(H) + O(N)
> Space Complexity: O(N)
*/

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        return (root->left == NULL && root->right == NULL);
    }

    void addLeaves(Node *root, vector<int> &ans)
    {
        //* using preorder traversal
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }

        if (root->left)
        {
            addLeaves(root->left, ans);
        }
        if (root->right)
        {
            addLeaves(root->right, ans);
        }
    }

    void addLeftBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->left;
        while (curr != NULL)
        {
            if (!isLeaf(curr))
            {
                ans.push_back(curr->data);
            }

            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void addRightBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr != NULL)
        {
            if (!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }

            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        if (!isLeaf(root))
        {
            ans.push_back(root->data);
        }

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};
