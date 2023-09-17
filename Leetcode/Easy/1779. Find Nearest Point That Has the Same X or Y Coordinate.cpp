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
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int smallestIndex = INT_MAX;
        int smallestDistance = INT_MAX;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int currDistance = abs(points[i][0] - x) +
                                   abs(points[i][1] - y);
                if (currDistance < smallestDistance)
                {
                    smallestDistance = currDistance;
                    smallestIndex = i;
                }
            }
        }
        return smallestIndex == INT_MAX ? -1 : smallestIndex;
    }
};