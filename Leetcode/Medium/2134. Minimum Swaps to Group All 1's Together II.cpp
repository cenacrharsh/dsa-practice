#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Sliding Window

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        //* we maintain a sliding window of size == number of 1's in the array, and the number of 0's in the window will be the number of swaps required

        int numOfOnes = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                numOfOnes++;
            }
        }

        nums.insert(nums.end(), nums.begin(), nums.end()); //* to treat it as a circular array

        int left = 0, right = 0;
        int swaps = 0, minSwaps = INT_MAX;
        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                swaps++;
            }
            if (right - left + 1 > numOfOnes)
            {
                if (nums[left] == 0)
                {
                    swaps--;
                }
                left++;
            }
            if (right - left + 1 == numOfOnes)
            {
                minSwaps = min(swaps, minSwaps);
            }
            right++;
        }
        return minSwaps;
    }
};