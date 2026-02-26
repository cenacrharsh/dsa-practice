#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=28

//- f(i, j, isTrue) -> f(0, n-1, 1) -> isTrue = 1 means true/0 means false -> number of ways we can generate True in range 0 to n-1

//! Memoization DP

/*
> Time Complexity: O(N * N * 2) + O(N)
> Space Complexity: O(N * N * 2) + O(N)
*/

int mod = 1000000007;
long long helper(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    //* we are traversing over operands T(&T|)F -> i+1 to j-1
    long long ways = 0;
    for (int index = i + 1; index <= j - 1; index += 2)
    {
        long long leftTrue = helper(i, index - 1, 1, exp, dp);
        long long leftFalse = helper(i, index - 1, 0, exp, dp);

        long long rightTrue = helper(index + 1, j, 1, exp, dp);
        long long rightFalse = helper(index + 1, j, 0, exp, dp);

        if (exp[index] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftFalse * rightFalse) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
        }
        else if (exp[index] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
        }
        else if (exp[index] == '^')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return helper(0, n - 1, 1, exp, dp);
}

//! Recursion -> Top Down Approach

int mod = 1000000007;
long long helper(int i, int j, int isTrue, string &exp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        return exp[i] == 'F';
    }

    //* we are traversing over operands T(&T|)F -> i+1 to j-1
    long long ways = 0;
    for (int index = i + 1; index <= j - 1; index += 2)
    {
        long long leftTrue = helper(i, index - 1, 1, exp);
        long long leftFalse = helper(i, index - 1, 0, exp);

        long long rightTrue = helper(index + 1, j, 1, exp);
        long long rightFalse = helper(index + 1, j, 0, exp);

        if (exp[index] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftFalse * rightFalse) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
        }
        else if (exp[index] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
        }
        else if (exp[index] == '^')
        {
            if (isTrue)
            {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
            else
            {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
    }
    return ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    return helper(0, n - 1, 1, exp);
}