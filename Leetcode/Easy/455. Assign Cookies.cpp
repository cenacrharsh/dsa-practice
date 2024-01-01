#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int ans = 0;
        while (i < s.size() && j < g.size())
        {
            if (s[i] >= g[j])
            {
                i++;
                j++;
                ans++;
            }
            else if (s[i] < g[j])
            {
                i++;
            }
        }
        return ans;
    }
};