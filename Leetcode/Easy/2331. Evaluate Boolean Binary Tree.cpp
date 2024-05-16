#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    bool helper(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }

        int leftChild = helper(root->left);
        int rightChild = helper(root->right);
        int operand = root->val;

        if(operand == 2) {
            return leftChild | rightChild;
        } else {
            return leftChild & rightChild;
        }
    }

    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};