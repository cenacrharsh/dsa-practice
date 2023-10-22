#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

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
    vector<int> bottomView(Node *root)
    {
        //* last node in each vertical will be our bottom view of binary tree
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> m; //* (vertical, node->val) to store first node of each vertical
        queue<pair<Node *, int>> q; //* node, vertical

        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int vertical = it.second;

            //* since we need last node in each vertical we'll replace everytime we get a new node in vertical
            m[vertical] = node->data;

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