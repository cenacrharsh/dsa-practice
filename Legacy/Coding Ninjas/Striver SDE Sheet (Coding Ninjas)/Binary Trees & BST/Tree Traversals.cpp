#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ySp2epYvgTE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=14

/*
> Time Complexity: O(3N)
> Space Complexity: O(3N)
*/

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        //* if number == 1 it's part of preorder, increment 1 to 2 and insert left subtree
        if (it.second == 1)
        {
            preorder.push_back(it.first->data);

            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        //* if number == 2 it's part of inorder, increment 2 to 3 and insert right subtree
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);

            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        //* if number == 3 it's part of postorder, don't push it back again
        else
        {
            postorder.push_back(it.first->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
