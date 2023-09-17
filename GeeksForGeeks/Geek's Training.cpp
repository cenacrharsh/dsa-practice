#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * 4 * 3)
> Space Complexity: O(4)
*/

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<int> prev(4, 0);

    // base cases for day == 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int prevTask = 0; prevTask < 4; prevTask++)
        {
            temp[prevTask] = 0;
            for (int currTask = 0; currTask < 3; currTask++)
            {
                if (currTask != prevTask)
                {
                    temp[prevTask] = max(temp[prevTask], points[day][currTask] + prev[currTask]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}

//! Tabulation DP -> Bottom Up Approach
int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // base cases for day == 0
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
                if (currTask != prevTask)
                {
                    // dp[day - 1][currTask] => maxPoints earned if on the prev day our currTask was passed as the prevTask so that today we can choose currTask as our task for the day
                    int currPoints = points[day][currTask] + dp[day - 1][currTask];
                    dp[day][prevTask] = max(dp[day][prevTask], currPoints);
                }
            }
        }
    }

    return dp[n - 1][3];
}

//! Memoization DP

/*
> Time Complexity: O(N * 4) * 3 => for n days we can have 4 states at max, and loop of size 3 is being run every time
> Space Complexity: O(N * 4) + O(N)
*/

int helper(vector<vector<int>> &points, int day, int prevTask, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        // on the last day we simply do the task which will give max points
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

int maximumPoints(vector<vector<int>> &points, int n)
{
    // n days and 3 tasks, so we pass day = n - 1 and task = 3 show no task has been done
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(points, n - 1, 3, dp);
}

//! Recursion -> Top Down Approach
int helper(vector<vector<int>> &points, int day, int prevTask)
{
    if (day == 0)
    {
        // on the last day we simply do the task which will give max points
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
int maximumPoints(vector<vector<int>> &points, int n)
{
    // n days and 3 tasks, so we pass day = n - 1 and task = 3 show no task has been done
    return helper(points, n - 1, 3);
}