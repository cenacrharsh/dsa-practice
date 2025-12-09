#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N) + O(N) => Hash calculation then LIS creation
> Space Complexity: O(N + N) => DP + LIS
*/

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n, 0);
        int maxLen = 1;
        int lastIndex = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;
        lis.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            lis.push_back(arr[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        // for(auto it : lis) {
        //   cout << it << " ";
        // }
        // cout << endl;
        return lis;
    }
};

//! Memoization DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Recursion -> Top Down Approach

/*
> Time Complexity: O()
> Space Complexity: O()
*/