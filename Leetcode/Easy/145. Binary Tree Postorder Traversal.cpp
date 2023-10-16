#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=RlUu72JrOCQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=6

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Using Recursion

class Solution
{
public:
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        //* left
        helper(root->left, ans);

        //* right
        helper(root->right, ans);

        //* root
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

//! Using Iteration (1 stack)

/*
> Time Complexity: O(2 * N) => once to push in stack, and once to traverse and check root
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> nodesLeft;
        TreeNode *currNode = root;

        // we keep going left as long as possible then we move right and try to move as left as we can again
        while (currNode != NULL || !nodesLeft.empty())
        {
            if (currNode != NULL)
            {
                nodesLeft.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                // since we reached NULL for our currNode while going left so now we try to go right
                TreeNode *tempNode = nodesLeft.top()->right;

                // we try to move right and it's also NULL
                if (tempNode == NULL)
                {
                    // we have reached the extreme leftmost node or the extreme rightmost node so we add it to our answer
                    tempNode = nodesLeft.top();
                    nodesLeft.pop();
                    ans.push_back(tempNode->val);

                    // check if out tempNode has a root
                    while (!nodesLeft.empty() && tempNode == nodesLeft.top()->right)
                    {
                        // if root exists we add it out answer
                        tempNode = nodesLeft.top();
                        nodesLeft.pop();
                        ans.push_back(tempNode->val);
                    }
                }
                else
                {
                    // setting the right node as currNode so that we can restart the process of trying to move as left as possible, as once again when we'll hit the end we'll move right and then try to move left again
                    currNode = tempNode;
                }
            }
        }
        return ans;
    }
};

//! Using Iteration (2 stack)

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *currNode = st1.top();
            st1.pop();

            // first insert the root
            st2.push(currNode);

            // then insert the left node
            if (currNode->left != NULL)
            {
                st1.push(currNode->left);
            }

            // then insert the right node
            if (currNode->right != NULL)
            {
                st1.push(currNode->right);
            }
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};
