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

// # Tutorial: https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

/*
> Time Complexity: O(N) + O(N) => parent track traversal + traversal to find distance k
> Space Complexity: O(N) + O(N) + O(N) => parent_track, queue, visited
*/

int findMaxTime(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent_track, BinaryTreeNode<int> *target)
{
    map<BinaryTreeNode<int> *, bool> visited;
    int time = 0;
    queue<BinaryTreeNode<int> *> q;
    q.push(target);
    visited[target] = true;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *currNode = q.front();
            q.pop();

            //* check left, right and parent
            if (parent_track[currNode] && !visited[parent_track[currNode]])
            {
                flag = true;
                q.push(parent_track[currNode]);
                visited[parent_track[currNode]] = true;
            }
            if (currNode->left && !visited[currNode->left])
            {
                flag = true;
                q.push(currNode->left);
                visited[currNode->left] = true;
            }
            if (currNode->right && !visited[currNode->right])
            {
                flag = true;
                q.push(currNode->right);
                visited[currNode->right] = true;
            }
        }
        if (flag)
            time++;
    }
    return time;
}

BinaryTreeNode<int> *markParent(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent_track, int start)
{
    BinaryTreeNode<int> *target;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currNode = q.front();
        q.pop();

        if (currNode->data == start)
        {
            target = currNode;
        }

        if (currNode->left)
        {
            parent_track[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            parent_track[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
    return target;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent_track; //* (node, parent)
    BinaryTreeNode<int> *target = markParent(root, parent_track, start);

    return findMaxTime(parent_track, target);
}
