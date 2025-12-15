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
> Time Complexity: O(N^2) + O(N^2)
> Space Complexity: O(N + N)
*/

class Solution
{
public:
    int LongestBitonicSequence(vector<int> arr)
    {
        //* LIS / LDS / LIS + LDS => Longest Bitonic Subsequence
        //* we'll maintain 2 dp arrays, one from the left and another from the right (acts as decreasing if viewed from left to right)
        //* we'll combine both to obtain bitonic (minus 1 to remove common element)

        int n = arr.size();
        vector<int> dp1(n, 1), dp2(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = n - 1; prev > i; prev--)
            {
                if (arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i])
                {
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            maxLen = max(maxLen, (dp1[i] + dp2[i] - 1));
        }
        return maxLen;
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