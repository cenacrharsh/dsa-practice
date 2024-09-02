#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    void helper(Node *node, vector<int> &ans)
    {
        // Recursively call dfs for each child of the current node
        for (Node *child : node->children)
        {
            helper(child, ans);
        }

        // Append the value of the current node to the result vector
        ans.push_back(node->val);
    };

    vector<int> postorder(Node *root)
    {
        // If the root is null, return an empty vector
        if (!root)
            return {};

        vector<int> ans;

        // Start DFS from the root
        helper(root, ans);

        // Return the result vector containing node values in post-order
        return ans;
    }
};