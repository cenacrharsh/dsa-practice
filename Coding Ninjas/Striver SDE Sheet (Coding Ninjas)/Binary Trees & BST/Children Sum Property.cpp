#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// # Tutorial: https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35

/*
> Time Complexity: O(N)
> Space Complexity: O(Heignt) ~ O(N) if skew tree
*/

void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    int sumOfChildren = 0;
    if (root->left != NULL)
    {
        sumOfChildren += root->left->data;
    }
    if (root->right != NULL)
    {
        sumOfChildren += root->right->data;
    }

    if (sumOfChildren >= root->data)
    {
        root->data = sumOfChildren;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
    {
        total += root->left->data;
    }
    if (root->right)
    {
        total += root->right->data;
    }
    //* don't update if leaf nodes
    if (root->left || root->right)
    {
        root->data = total;
    }
}