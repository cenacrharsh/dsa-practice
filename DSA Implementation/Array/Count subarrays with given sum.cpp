#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, Hashmap + 2 Pointers

/*
> Time Complexity: O(N * 1) => O(N * N) in worst case => O(N * Log N) if ordered map
> Space Complexity: O(N)
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int target = prefixSum - k;
            if (mp.find(target) != mp.end())
            {
                count += mp[target];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};

//! Better, 2 Loops for subarrays

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

//! Brute Force, 3 Loops for subarrays

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/