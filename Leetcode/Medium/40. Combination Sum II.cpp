#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=G1fRTGRxXU8

//! Backtracking (2nd Pattern of Solving Array Problems Involving Recursion)

/*
> Time Complexity: O(2^N * K) => we can have 2^N subsequences for N distinct elements and K is the time required to insert inside the data structure
> Space Complexity: O(K * X) => where X is the number of combinations
*/

class Solution
{
public:
    //* using approach of 39. Combination Sum, we would have to use a set as a data structure instead of vector to store all possible outcomes since we don't want duplicates which would increase the TC by a factor of Log(N) and to avoid that we'll use a different approach using subsequences otherwise the prev approach would also work fine by just using set and (index + 1) in pick element calls since we can't use same element twice in this problem

    void helper(int currIndex, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int remainingTarget)
    {
        if (remainingTarget == 0)
        {
            ans.push_back(ds);
            return;
        }

        //* by using the logic that for every place we can pick any of the eligible elements present in the array and if say element X is already picked up and X is present in some other index as well we won't try that combination as it'll produce duplicate results, thereby effectively avoiding repeating combinations while creating combinations itself thereby saving on TC
        for (int i = currIndex; i < candidates.size(); i++)
        {
            //* the check i > currIndex is very important because we don't want to stop picking elements if it's the first time, say the first element we are about to pick up was picked up as the last element as well in prev iteration since array can have duplicate elements, if i > currIndex is not present it won't allow to pick the same element again, instead what we really want is in current iteration if element X has been picked up don't pick it up again hence we skip the check for first index
            if (i > currIndex && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            //* if the remaining elements are greater than remainingTarget then we don't have to continue with that combination since due to sorting we know elements that follow would also be higher than target meaning we can't achieve a sum of target using this combination
            if (candidates[i] > remainingTarget)
            {
                break;
            }

            ds.push_back(candidates[i]);
            helper(i + 1, ds, ans, candidates, remainingTarget - candidates[i]);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); //* since we need combinations in sorted order
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0, ds, ans, candidates, target);
        return ans;
    }
};