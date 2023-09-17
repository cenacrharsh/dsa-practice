#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<Node *> nodesLeft;
        nodesLeft.push(root);

        while (!nodesLeft.empty())
        {
            int levelSize = nodesLeft.size();
            vector<int> currLevel;
            for (int i = 0; i < levelSize; i++)
            {
                Node *currNode = nodesLeft.front();
                nodesLeft.pop();

                currLevel.push_back(currNode->val);
                for (int j = 0; j < (currNode->children).size(); j++)
                {
                    nodesLeft.push((currNode->children)[j]);
                }
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};