#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=XmSOWnL6T_I

class Solution
{
public:
    int countSubstrings(string s)
    {
        //* we travel across a diagonal of a square matrix, all diagonals start from first row and end on first column
        //* to check if string is pallindrome, it's first and last characters must be equal and string in b/w first & last char must be a pallindrome
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;

        //* gap refers to length b/w starting and ending character
        for (int gap = 0; gap < s.size(); gap++)
        {
            //* all diagonals start from row = 0, and end at j = s.size() - 1
            for (int i = 0, j = gap; j < s.size(); i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = true;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    //* dp[i + 1][j - 1] is diagonally south-west to curr charcter which contains info about string present in b/w first and last char
                    if ((s[i] == s[j]) && (dp[i + 1][j - 1] == true))
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }

                if (dp[i][j] == true)
                {
                    count++;
                }
            }
        }
        return count;
    }
};