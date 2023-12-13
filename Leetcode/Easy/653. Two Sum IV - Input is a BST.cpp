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

// # Tutorial: https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53

/*
> Time Complexity: O(N)
> Space Complexity: 2 * O(H)
*/

class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    bool reverse; //* reverse: true => before, reverse: false => next

    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            myStack.push(root);
            if (reverse)
            {
                //* reverse: true => before
                root = root->right;
            }
            else
            {
                //* reverse: false => next;
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    //* return true if we have elements left
    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        TreeNode *tempNode = myStack.top();
        myStack.pop();
        if (reverse)
        {
            // reverse: true => before
            pushAll(tempNode->left);
        }
        else
        {
            // reverse: false => next;
            pushAll(tempNode->right);
        }
        return tempNode->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return false;
        }
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();
        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = left.next();
            }
            else
            {
                j = right.next();
            }
        }
        return false;
    }
};