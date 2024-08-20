#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    //* returns max total Alice can get
    int helper(vector<int> &piles, int left, int right, vector<vector<int>> &dp)
    {
        if (left > right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        //* if even number of elements are present it indicates it's Alices turn to pick
        bool flag = false;
        if ((right - left) % 2 == 0)
        {
            flag = true;
        }

        int leftValue = flag ? piles[left] : 0;
        int rightValue = flag ? piles[right] : 0;

        //* picks left element
        int leftPick = helper(piles, left + 1, right, dp) + leftValue;

        //* picks right element
        int rightPick = helper(piles, left, right - 1, dp) + rightValue;

        return dp[left][right] = max(leftPick, rightPick);
    }

    bool stoneGame(vector<int> &piles)
    {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        int aliceTotal = helper(piles, 0, piles.size() - 1, dp);
        int bobTotal = accumulate(piles.begin(), piles.end(), 0) - aliceTotal;
        return aliceTotal > bobTotal;
    }
};