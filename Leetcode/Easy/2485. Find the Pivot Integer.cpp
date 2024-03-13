#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Prefix Sum

class Solution
{
public:
    int pivotInteger(int n)
    {
        int sum = n * (n + 1) / 2;
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + i;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            int leftSum = prefix[i];
            int rightSum = sum - prefix[i] + i;
            if (leftSum == rightSum)
            {
                ans = i;
            }
        }
        return ans;
    }
};