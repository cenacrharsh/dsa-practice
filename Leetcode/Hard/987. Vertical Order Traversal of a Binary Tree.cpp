#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23

/*
> Time Complexity: O(N) * O(Log (N)) => N for traversal and log(N) for insertion in multiset
> Space Complexity: O(N) + O(N)
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        //* we'll treat it as coordinates where each root is 0 and to the left we have -2 -1 and to the rigth we have +1 +2 so basically it's -2 -1 0 1 2
        //* for levels we'll start with 0 and keep going 0 1 2 3 4
        //* whenever we move left, vetical - 1 and level + 1 happens
        //* whenever we move right, vetical + 1 and level + 1 happens
        //* any traversal can be used to create the data structure nodes, we'll use level order traversal

        map<int, map<int, multiset<int>>> nodes; //* vertical, (levels, nodes) => for each vertical we have multiple levels and in each level we have multiple nodes which can have same values hence we use a multiset

        queue<pair<TreeNode *, pair<int, int>>> todo; //* node, (vertical, level)
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto curr = todo.front();
            todo.pop();

            TreeNode *node = curr.first;
            int vertical = curr.second.first;
            int level = curr.second.second;

            nodes[vertical][level].insert(node->val);

            if (node->left)
            {
                todo.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {vertical + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        //* since it's a map, vertical are arranged in asc order like -2 -1 0 1 2..., inside it (levels, nodes) is also a map so levels are in asc order as well like 0 1 2 3... and inside each level we have a multiset of values (as we sorted values with duplicates)
        for (auto p : nodes)
        {
            vector<int> col;
            //* traverse the map of (levels, nodes) in curr vertical
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};