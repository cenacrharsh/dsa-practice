#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=3WaxQMELSkw

//! Space Optimized Tabulation DP
class Solution
{
public:
    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }
            int notPick = prev;
            prev2 = prev;
            prev = max(pick, notPick);
        }
        return prev;
    }

    int houseRobber(vector<int> &money)
    {
        vector<int> temp1, temp2;
        if (money.size() == 1)
        {
            return nonAdjacent(money);
        }

        for (int i = 0; i < money.size(); i++)
        {
            if (i != 0)
                temp1.push_back(money[i]);
            if (i != money.size() - 1)
                temp2.push_back(money[i]);
        }
        return max(nonAdjacent(temp1), nonAdjacent(temp2));
    }
};

//! Tabulation DP -> Bottom Up Approach

//! Memoization DP

//! Recursion -> Top Down Approach