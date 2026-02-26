#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool isParentSum(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }

    int sumOfChildren = 0;
    if (root->left)
    {
        sumOfChildren += root->left->data;
    }
    if (root->right)
    {
        sumOfChildren += root->right->data;
    }

    if (root->data == sumOfChildren)
    {
        return isParentSum(root->left) && isParentSum(root->right);
    }

    return false;
}