#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=LL0tVxlAeV4

class Solution
{
public:
    int n;
    int memo[50001];

    //* find the first job whose startTime >= current jobs endTime
    int getNextIndex(int startIndex, int currentJobEndTime, vector<vector<int>> &jobs)
    {
        int l = startIndex, r = n - 1;
        int ans = n + 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (jobs[mid][0] >= currentJobEndTime)
            {
                //* we can take this task
                ans = mid;
                r = mid - 1; //* look for smaller values
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    int helper(int currIndex, vector<vector<int>> &jobs)
    {
        if (currIndex >= n)
        {
            return 0;
        }

        if (memo[currIndex] != -1)
        {
            return memo[currIndex];
        }

        //* find such job whose startTime >= endTime of currentJob, and search begins from currIndex + 1
        int nextJob = getNextIndex(currIndex + 1, jobs[currIndex][1], jobs);

        int take = jobs[currIndex][2] + helper(nextJob, jobs);
        int notTake = 0 + helper(currIndex + 1, jobs);

        return memo[currIndex] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = profit.size();

        vector<vector<int>> jobs(n, vector<int>(3, 0)); //> [{startTime, endTime, profit}]
        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        //* sort according to startTime
        auto comp = [&](auto &vec1, auto &vec2)
        {
            return vec1[0] <= vec2[0];
        };
        sort(begin(jobs), end(jobs), comp);

        memset(memo, -1, sizeof(memo));

        return helper(0, jobs);
    }
};