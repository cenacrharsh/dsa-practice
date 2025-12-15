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
> Time Complexity: O(N * Log(N)) + O(N^2 * L)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
        {
            return false;
        }

        int first = 0, second = 0;
        while (first < s1.size())
        {
            if (second < s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        //* if both strings reach thier end together means both had same character with 1 difference only since we already compared their sizes
        if (first == s1.size() && second == s2.size())
        {
            return true;
        }
        return false;
    }

    static bool comparator(string &s1, string &s2)
    {
        if (s1.size() < s2.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int longestStrChain(vector<string> &words)
    {
        //* almost like LIS, there we compared values of 2 adjacent elements here we need to compare 2 strings

        //* here we want ans in any sequence i.e. subset not a subsequence
        sort(words.begin(), words.end(), comparator);

        int n = words.size();
        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
            }
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