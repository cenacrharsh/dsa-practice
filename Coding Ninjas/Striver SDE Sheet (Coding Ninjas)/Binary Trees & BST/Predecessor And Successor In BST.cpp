#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// # Tutorial: https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=51

/*
> Time Complexity: O(H)
> Space Complexity: O(1)
*/

int predecessorHelper(TreeNode *root, int key)
{
    TreeNode *predecessor = new TreeNode(-1);
    while (root != NULL)
    {
        //* we need element smaller than key
        if (root->data >= key)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right; //* we need a value > possible ans but < key
        }
    }
    return predecessor->data;
}
int successorHelper(TreeNode *root, int key)
{
    TreeNode *successor = new TreeNode(-1);
    while (root != NULL)
    {
        //* we need element bigger than key
        if (root->data <= key)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left; //* we need a value < possible ans but > key
        }
    }
    return successor->data;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> ans;
    ans.first = predecessorHelper(root, key);
    ans.second = successorHelper(root, key);
    return ans;
}