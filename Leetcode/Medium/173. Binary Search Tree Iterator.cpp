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

// # Tutorial: https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52

/*
> Time Complexity: O(1)
> Space Complexity: O(H)
*/

class BSTIterator
{
private:
    stack<TreeNode *> myStack;

    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            myStack.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
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
        //* if the current node has a right node we push it and all of it's left nodes inside the stack
        pushAll(tempNode->right);
        return tempNode->val;
    }
};