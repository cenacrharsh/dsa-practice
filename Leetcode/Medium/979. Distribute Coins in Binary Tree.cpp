#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=MfXxic8IhkI

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    int helper(TreeNode* node, int& steps) {
        if(node == NULL) {
            return 0;
        }

        int leftSubtreeRequired = helper(node->left, steps);
        int rightSubtreeRequired = helper(node->right, steps);

        steps += abs(leftSubtreeRequired) + abs(rightSubtreeRequired);
        return (node->val - 1) + leftSubtreeRequired + rightSubtreeRequired;
    }

    int distributeCoins(TreeNode* root) {
        int steps = 0;
        helper(root, steps);
        return steps;
    }
};