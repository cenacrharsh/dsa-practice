#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeList;
        unordered_map<int, bool> hasParent;
        for(int i = 0; i < descriptions.size(); i++) {
            TreeNode* parentNode;
            TreeNode* childNode;
            if(nodeList.find(descriptions[i][0]) == nodeList.end()) {
                parentNode = new TreeNode(descriptions[i][0]);
                nodeList[descriptions[i][0]] = parentNode;
            } else {
                parentNode = nodeList[descriptions[i][0]];
            }

            if(nodeList.find(descriptions[i][1]) == nodeList.end()) {
                childNode = new TreeNode(descriptions[i][1]);
                nodeList[descriptions[i][1]] = childNode;
            } else {
                childNode = nodeList[descriptions[i][1]];
            }

            if(descriptions[i][2] == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }

            //* maintain which nodes have a parent
            hasParent[descriptions[i][1]] = true;
        }

        //* find root node
        TreeNode* ans;
        for(auto it : nodeList) {
            if(hasParent.find(it.first) == hasParent.end()) {
                ans = nodeList[it.first];
            }
        }
        return ans;
    }
};