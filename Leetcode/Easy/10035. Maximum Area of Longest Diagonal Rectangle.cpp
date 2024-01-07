#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        double maxDiagonal = INT_MIN, maxArea = INT_MIN;
        for (int i = 0; i < dimensions.size(); i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];

            double diagonal = sqrt((l * l) + (b * b));
            double area = l * b;
            if (diagonal > maxDiagonal)
            {
                maxDiagonal = diagonal;
                maxArea = area;
            }
            else if (diagonal == maxDiagonal)
            {
                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
};