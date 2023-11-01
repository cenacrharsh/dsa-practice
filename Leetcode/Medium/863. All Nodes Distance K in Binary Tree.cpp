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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// # Tutorial: https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32

/*
> Time Complexity: O(N) + O(N) => parent track traversal + traversal to find distance k
> Space Complexity: O(N) + O(N) + O(N) => parent_track, queue, visited
*/

class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

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
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track; //* (node, parent)
        markParents(root, parent_track);

        unordered_map<TreeNode *, bool> visited;
        int distance = 0;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        while (!q.empty())
        {
            if (distance++ == k)
                break;

            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                //* check left, right and parent
                if (parent_track[currNode] && !visited[parent_track[currNode]])
                {
                    q.push(parent_track[currNode]);
                    visited[parent_track[currNode]] = true;
                }
                if (currNode->left && !visited[currNode->left])
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right && !visited[currNode->right])
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();
            ans.push_back(currNode->val);
        }
        return ans;
    }
};
