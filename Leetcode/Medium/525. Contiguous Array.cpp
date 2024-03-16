#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp; //* sum -> index
        mp[0] = -1;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ? 1 : -1;
            //* same sum indicates we have had equal number of 0s and 1s b/w last time we had same sum and now
            if (mp.find(sum) != mp.end())
            {
                int len = i - mp[sum];
                maxLen = max(len, maxLen);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};