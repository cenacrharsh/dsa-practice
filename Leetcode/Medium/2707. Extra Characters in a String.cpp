#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=LlHTq13EhMw

/*
> Time Complexity: O(N^2) => for every index we go to every substring from that index
> Space Complexity: O(N) + O(S) => where s is size of string
*/

class Solution
{
public:
    int helper(string &s, unordered_map<string, int> &mp, vector<int> &dp, int currIdx)
    {
        if (currIdx >= s.size())
            return 0;

        if (dp[currIdx] != -1)
            return dp[currIdx];

        string currStr = "";
        int ans = s.size();
        for (int i = currIdx; i < s.size(); i++)
        {
            currStr.push_back(s[i]);
            int count = ((mp.count(currStr)) ? 0 : currStr.size()) + helper(s, mp, dp, i + 1);
            ans = min(ans, count);
        }
        return dp[currIdx] = ans;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        vector<int> dp(s.size(), -1);
        unordered_map<string, int> mp;
        for (int i = 0; i < dictionary.size(); i++)
        {
            mp[dictionary[i]]++;
        }

        return helper(s, mp, dp, 0);
    }
};