#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=XjLT4TaXsgw

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N^2)
*/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;

        vector<unordered_map<int, int>> maps(nums.size()); //* array of map which contains cd v/s no. of subsequences ending at given index, having >=2 elements and given cd

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long cd = (long)nums[i] - (long)nums[j];
                if (cd <= INT_MIN || cd >= INT_MAX)
                {
                    continue;
                }

                int apsEndingAtI = maps[i][cd];
                int apsEndingAtJ = maps[j][cd];

                ans += apsEndingAtJ;
                maps[i][cd] = apsEndingAtI + apsEndingAtJ + 1;
            }
        }

        return ans;
    }
};