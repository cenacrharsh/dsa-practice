#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=5

//! Space Optimized Tabulation DP

//! Tabulation DP -> Bottom Up Approach
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int prevTask = 0; prevTask < 4; prevTask++)
        {
            dp[day][prevTask] = 0;
            for (int currTask = 0; currTask < 3; currTask++)
            {
                if (prevTask != currTask)
                {
                    int currPoints = points[day][currTask] + dp[day - 1][currTask];
                    dp[day][prevTask] = max(dp[day][prevTask], currPoints);
                }
            }
        }
    }

    return dp[n - 1][3];
}

//! Memoization DP
int helper(vector<vector<int>> &points, int day, int prevTask, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxPoints = 0;
        for (int currTask = 0; currTask < 3; currTask++)
        {
            if (currTask != prevTask)
            {
                maxPoints = max(maxPoints, points[day][currTask]);
            }
        }
        return maxPoints;
    }

    if (dp[day][prevTask] != -1)
    {
        return dp[day][prevTask];
    }

    int maxPoints = 0;
    for (int currTask = 0; currTask < 3; currTask++)
    {
        if (currTask != prevTask)
        {
            int currPoints = points[day][currTask] + helper(points, day - 1, currTask, dp);
            maxPoints = max(maxPoints, currPoints);
        }
    }

    return dp[day][prevTask] = maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // we need n * 4 matrix as for tasks we have values of 0, 1, 2, 3 (3 signifying no task has been done yet)
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(points, n - 1, 3, dp);
}

//! Recursion -> Top Down Approach
int helper(vector<vector<int>> &points, int day, int prevTask)
{
    if (day == 0)
    {
        int maxPoints = 0;
        for (int currTask = 0; currTask < 3; currTask++)
        {
            if (currTask != prevTask)
            {
                maxPoints = max(maxPoints, points[day][currTask]);
            }
        }
        return maxPoints;
    }

    int maxPoints = 0;
    for (int currTask = 0; currTask < 3; currTask++)
    {
        if (currTask != prevTask)
        {
            int currPoints = points[day][currTask] + helper(points, day - 1, currTask);
            maxPoints = max(maxPoints, currPoints);
        }
    }

    return maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // 3 signifies on day = 0, no task has been done
    return helper(points, n - 1, 3);
}