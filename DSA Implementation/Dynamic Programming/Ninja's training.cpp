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
> Time Complexity: O(N * 4 * 3)
> Space Complexity: O(4)
*/

class Solution
{
public:
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        //* f(n - 1, x) -> max merit points from day 0 -> day (n - 1), x tracks the task done on previous day

        int n = matrix.size();
        vector<int> prev(4, 0);

        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int currDday = 1; currDday < n; currDday++)
        {
            vector<int> temp(4, 0);
            for (int prevTask = 0; prevTask < 4; prevTask++)
            {
                for (int task = 0; task < 3; task++)
                {
                    if (task != prevTask)
                    {
                        int currPoints = matrix[currDday][task] + prev[task];
                        temp[prevTask] = max(temp[prevTask], currPoints);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * 4 * 3)
> Space Complexity: O(N * 4)
*/

class Solution
{
public:
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        //* f(n - 1, x) -> max merit points from day 0 -> day (n - 1), x tracks the task done on previous day

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); //* we are trying to access index prevTask = 3, hence dp of array N * 4 required

        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int currDday = 1; currDday < n; currDday++)
        {
            for (int prevTask = 0; prevTask < 4; prevTask++)
            {
                int maxPoints = INT_MIN;
                for (int task = 0; task < 3; task++)
                {
                    if (task != prevTask)
                    {
                        int currPoints = matrix[currDday][task] + dp[currDday - 1][task];
                        maxPoints = max(maxPoints, currPoints);
                    }
                }
                dp[currDday][prevTask] = maxPoints;
            }
        }

        return dp[n - 1][3];
    }
};

//! Memoization DP
/*
> Time Complexity: O([N * 4] * 3) -> N * 4 States (Days * Tasks), Loop of 3 for each state
> Space Complexity: O(N) + O(N * 4) -> Recursive Stack Space + Matrix
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currentDay, int prevTask, vector<vector<int>> &dp)
    {
        if (currentDay == 0)
        {
            int maxPoints = INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if (i != prevTask)
                {
                    maxPoints = max(maxPoints, matrix[0][i]);
                }
            }
            return maxPoints;
        }

        if (dp[currentDay][prevTask] != -1)
        {
            return dp[currentDay][prevTask];
        }

        int maxPoints = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevTask)
            {
                int currPoints = matrix[currentDay][i] + helper(matrix, currentDay - 1, i, dp);
                maxPoints = max(maxPoints, currPoints);
            }
        }
        return dp[currentDay][prevTask] = maxPoints;
    }

    int ninjaTraining(vector<vector<int>> &matrix)
    {
        //* f(n - 1, lastTask) -> max merit points from day 0 -> day (n-1), lastTask tracks the task done on previous day

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); //* we are trying to access index prevTask = [0,1,2,3] hence dp of array N * 4 required
        return helper(matrix, n - 1, 3, dp);           //* 0,1,2 represent the task done, 3 for no task done
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(N^3)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(vector<vector<int>> &matrix, int currentDay, int prevTask)
    {
        if (currentDay == 0)
        {
            int maxPoints = INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if (i != prevTask)
                {
                    maxPoints = max(maxPoints, matrix[0][i]);
                }
            }
            return maxPoints;
        }

        int maxPoints = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevTask)
            {
                int currPoints = matrix[currentDay][i] + helper(matrix, currentDay - 1, i);
                maxPoints = max(maxPoints, currPoints);
            }
        }
        return maxPoints;
    }

    int ninjaTraining(vector<vector<int>> &matrix)
    {
        //* f(n - 1, lastTask) -> max merit points from day 0 -> day (n-1), lastTask tracks the task done on previous day

        int n = matrix.size();
        return helper(matrix, n - 1, 3); //* 0,1,2 represent the task done, 3 for no task done
    }
};