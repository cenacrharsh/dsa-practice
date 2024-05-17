#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: 1325. Delete Leaves With a Given Value

/*
> Time Complexity: O(N)
> Space Complexity: O(N) -> Recursive Stack Space
*/

class Solution {
public:
    TreeNode* helper(TreeNode* node, int target) {
        if(node == NULL) {
            return NULL;
        }

        node->left = helper(node->left, target);
        node->right = helper(node->right, target);

        if(node->left == NULL && node->right == NULL && node->val == target) {
            return NULL;
        }
        return node;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root, target);
    }
};