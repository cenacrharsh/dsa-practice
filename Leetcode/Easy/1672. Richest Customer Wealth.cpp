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
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = INT_MIN;
        for (int i = 0; i < accounts.size(); i++)
        {
            int tempWealth = 0;
            for (int j = 0; j < accounts[0].size(); j++)
            {
                tempWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, tempWealth);
        }
        return maxWealth;
    }
};