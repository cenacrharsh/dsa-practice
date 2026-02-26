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

// # Tutorial: https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class NodeValue
{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSTHelper(TreeNode *root)
{
    //* an empty tree is a BST of size 0
    if (root == NULL)
    {
        return NodeValue(INT_MAX, INT_MIN, 0); //* since it's null for max_value we pass smallest number and for min_value we pass largest number, so that root is always greater than largest value from left and always smaller than smallest value from right
    }

    //* get values from left and right subtree of current tree
    NodeValue left = largestBSTHelper(root->left);
    NodeValue right = largestBSTHelper(root->right);

    //* if current node is greater than max value in left and smaller then min value in right then it's a valid BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    //* otherwise return (INT_MIN AND INT_MAX) so that parent can't be a valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode *root)
{
    return largestBSTHelper(root).maxSize;
}
