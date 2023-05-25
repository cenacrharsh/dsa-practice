#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=IexN60k62jo&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=38

//! Optimal

/*
> Time Complexity: O(N * log(N) + N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            //* if first iteration or current interval's first element is greater than previous intervals last element, we create a new interval
            if (ans.empty() || intervals[i][0] > ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                //* next interval overlaps with prev interval, so expand the interval to fit in the next interval if necessary
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

//! Brute Force

/*
> Time Complexity: O(N * log(N) + 2N) => 2N for checking each element
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // if next interval lies inside of current interval
            if (!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }

            // if next interval's beginning lies in between the current interval
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] <= end)
                {
                    end = max(end, intervals[j][1]);
                }
                else
                {
                    break;
                }
            }

            ans.push_back({start, end});
        }
        return ans;
    }
};
