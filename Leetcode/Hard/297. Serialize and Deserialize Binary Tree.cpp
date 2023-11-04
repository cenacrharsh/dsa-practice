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

// # Tutorial: https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=38

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Codec
{
public:
    //! Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }

        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode == NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(currNode->val) + ',');
            }

            if (currNode != NULL)
            {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    //! Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }

        stringstream s(data); //* stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)

        string str;
        getline(s, str, ','); //* getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            //* get the left node
            getline(s, str, ',');
            if (str == "#")
            {
                currNode->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                currNode->left = leftNode;
                q.push(leftNode);
            }

            //* get the right node
            getline(s, str, ',');
            if (str == "#")
            {
                currNode->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                currNode->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
