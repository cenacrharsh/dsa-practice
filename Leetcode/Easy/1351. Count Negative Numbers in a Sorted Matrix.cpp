#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=QqU24e6Es60

/*
> Time Complexity: O(M * log(N)) => M * N matrix
> Space Complexity: O(1)
*/

class Solution
{
public:
    int binarysearch(vector<vector<int>> &grid, int r, int si, int ei)
    {
        if (si > ei)
        {
            return 0;
        }

        int mid = ei - (ei - si) / 2;

        if (grid[r][mid] < 0)
        {
            return (ei - mid + 1) + binarysearch(grid, r, si, mid - 1);
        }

        return binarysearch(grid, r, mid + 1, ei);
    }

    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            count += binarysearch(grid, i, 0, grid[i].size() - 1);
        }
        return count;
    }
};