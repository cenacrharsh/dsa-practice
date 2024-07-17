#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Bit Manipulation

// # Tutorial: https://youtube.com/watch?v=LqKaUv1G3_I&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=43

/*
> Time Complexity: O(2^N * N)
> Space Complexity: ~ O(2^N * N) => nearabout not exact
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //* generate all numbers from 0->2^n-1, and check their last n bits where n = nums.size(), if ith bit is 1 we pick the ith number from nums in our subset else skip it

        int n = nums.size();
        vector<vector<int>> ans;
        for(int num = 0; num < (1 << n); num++) {
            vector<int> subset;
            //* check if ith bit is set bit
            for(int i = 0; i < n; i++) {
                if((num & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};


//! Using Backtracking (Pick & Not Pick)

// # Tutorial: https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8

/*
> Time Complexity: O(2^N) => for every index we have 2 options
> Space Complexity: O(N) => max depth of recursion tree at any given time is N
*/

class Solution
{
public:
    vector<vector<int>> helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> subSet, int index, int n)
    {
        if (index == n)
        {
            ans.push_back(subSet);
            return ans;
        }

        //> pick the particular index into the subsequence
        subSet.push_back(nums[index]);
        helper(nums, ans, subSet, index + 1, n);

        //> not pick the particular index into the subsequence
        subSet.pop_back();
        helper(nums, ans, subSet, index + 1, n);

        return ans;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subSet;
        return helper(nums, ans, subSet, 0, nums.size());
    }
};