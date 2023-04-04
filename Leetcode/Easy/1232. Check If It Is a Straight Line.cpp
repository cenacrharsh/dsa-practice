#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // a straight line can always be drawn using any 2 points, so no need to check, we need to check from 3 points
        // (y2 - y1)/(x2 - x1) == (y3 - y2)/(x3 - x2)

        // calc slope of line using first 2 points
        int xdiff = coordinates[1][0] - coordinates[0][0];
        int ydiff = coordinates[1][1] - coordinates[0][1];

        for (int i = 2; i < coordinates.size(); i++)
        {
            // calc slope using ith and (i-1)th point
            int currXdiff = coordinates[i][0] - coordinates[i - 1][0];
            int currYdiff = coordinates[i][1] - coordinates[i - 1][1];

            // we are using formula in * form to avoid division by 0
            if (ydiff * currXdiff != xdiff * currYdiff)
            {
                return false;
            }
        }
        return true;
    }
};