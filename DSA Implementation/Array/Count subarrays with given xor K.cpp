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
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        //* is there any subarray ending at index i and having a xor of k
        //* x ^ k = xr, where xr is xor of all elements till index i => x ^ k ^ k = xr ^ k => x = xr ^ k
        //* if from the start till index i if xr ^ k exists then we can take it in our answer

        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int xr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xr = xr ^ nums[i];
            int target = xr ^ k;
            if (mp.find(target) != mp.end())
            {
                count += mp[target];
            }
            mp[xr]++;
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