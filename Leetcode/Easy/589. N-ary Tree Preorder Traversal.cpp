#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    void helper(Node *root, vector<int> &ans)
    {
        ans.push_back(root->val);
        for (auto it : root->children)
        {
            helper(it, ans);
        }
    }

    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        helper(root, ans);
        return ans;
    }
};

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