#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N * Log(N)) + O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; i++)
        {
            ans += max(happiness[i] - i, 0);
        }
        return ans;
    }
};
