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

class Solution
{
public:
    int countSubsetsWithSumK(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 0; targetLeft <= target; targetLeft++)
            {
                int notTake = prev[targetLeft];
                int take = 0;
                if (arr[currIndex] <= targetLeft)
                {
                    take = prev[targetLeft - arr[currIndex]];
                }

                curr[targetLeft] = (take + notTake);
            }
            prev = curr;
        }

        return prev[target];
    }

    int countPartitions(int n, int diff, vector<int> &arr)
    {
        /*
            s1 + s2 = totalSum => s1 = totalSum - s2
            s1 - s2 = diff => totalSum - s2 - s2 = diff => s2 = (totalSum - diff) / 2
            so we are looking for subsets with sum = (totalSum - diff) / 2
            edge cases: (totalSum - diff) has to be > 0 since there are no -ve numbers so negative not possible, (totalSum - diff) must be even since after 2 we don't want any decimals since there are no fractions so subset sum can't be a fraction
        */

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)
        {
            return false;
        }

        int target = (totalSum - diff) / 2;
        return countSubsetsWithSumK(arr, target);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        //* boils down to, count the number of ways to partition the array into two subsets S1 and S2 such that: ∣S1−S2∣ = diff
        return countPartitions(nums.size(), target, nums);
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O()
> Space Complexity: O()
*/

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