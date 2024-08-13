#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=OyZFFqQtu98

//! Backtracking (1st Pattern of Solving Array Problems Involving Recursion)

/*
> Time Complexity: O(2^T * K) => where T is target and K is the time taken to insert element in the data structure, we have 2^T instead of 2^N because here we can choose same element multiple times so it's not just pick non pick but we can pick the same element until we reach target so it's 2^T

> Space Complexity: O(K * X) => where we assume X is the total number of combinations
*/

class Solution
{
public:
    void helper(int currIndex, vector<int> &tempSum, vector<vector<int>> &ans, vector<int> &candidates, int remainintTarget)
    {
        if (currIndex == candidates.size())
        {
            if (remainintTarget == 0)
            {
                ans.push_back(tempSum);
            }
            return;
        }

        // pick up the element
        if (candidates[currIndex] <= remainintTarget)
        {
            tempSum.push_back(candidates[currIndex]);
            helper(currIndex, tempSum, ans, candidates, remainintTarget - candidates[currIndex]); //* we stay at the same index because in the problem it states we can pick the same element any number of times so we'll come back to the same index and decide whether we want to pick the same element again or not
            tempSum.pop_back();                                                                   //* remove the element before recursive call without the element, i.e backtracking
        }

        //* not pick the element
        helper(currIndex + 1, tempSum, ans, candidates, remainintTarget);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> tempSum;
        vector<vector<int>> ans;
        helper(0, tempSum, ans, candidates, target);
        return ans;
    }
};