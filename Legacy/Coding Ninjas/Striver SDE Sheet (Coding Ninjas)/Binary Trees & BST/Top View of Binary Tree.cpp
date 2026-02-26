#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23

/*
> Time Complexity: O()
> Space Complexity: O()
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    //> Function to return a list of nodes visible from the top view from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //* first node in every vertical will be the top view of a binary tree
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> m;            //* (vertical, node->val) to store first node of each vertical
        queue<pair<Node *, int>> q; //* node, vertical

        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int vertical = it.second;

            //* we check if a node already exists for current vertical, if not we push it
            if (m.find(vertical) == m.end())
            {
                m[vertical] = node->data;
            }

            if (node->left != NULL)
            {
                q.push({node->left, vertical - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, vertical + 1});
            }
        }
        //* since it's a map it's already sorted as -2 -1 0 1 2...
        for (auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};