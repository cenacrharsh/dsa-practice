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

// # Tutorial: https://www.youtube.com/watch?v=9TJYWh0adfk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47

//! Using Iteration + Inorder Traversal

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        if (root == NULL)
            return ans;

        stack<TreeNode *> nodesLeft;
        TreeNode *currNode = root;

        while (currNode != NULL || !nodesLeft.empty())
        {
            //* push all the left nodes of the currNode
            while (currNode != NULL)
            {
                nodesLeft.push(currNode);
                currNode = currNode->left;
            }

            //* pop out the last pushed node from stack
            currNode = nodesLeft.top();
            nodesLeft.pop();

            k--;
            if (k == 0)
            {
                ans = currNode->val;
            }

            //* now move to the right side of the currNode if there is any
            currNode = currNode->right;
        }
        return ans;
    }
};

//! Using Priority Queue

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    void traverse(TreeNode *root, int k, priority_queue<int> &pq)
    {
        if (root == NULL)
        {
            return;
        }
        pq.push(root->val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        traverse(root->left, k, pq);
        traverse(root->right, k, pq);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        priority_queue<int> pq;
        traverse(root, k, pq);
        return pq.top();
    }
};