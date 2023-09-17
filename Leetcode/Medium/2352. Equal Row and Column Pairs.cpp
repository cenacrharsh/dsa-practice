#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Use a map of vectors

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        map<vector<int>, int> hashmap;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            hashmap[grid[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(grid[j][i]);
            }
            ans += hashmap[temp];
        }
        return ans;
    }
};