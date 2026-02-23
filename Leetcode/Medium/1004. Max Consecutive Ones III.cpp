#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        //* optimized sliding window we don't let window size drop below the max size we have found already as that's our ans if we don't find anything bigger than that so no point in shrinking window below this size and then increasing it again, thus removing the inner while loop

        int left = 0, right = 0, maxCount = 0, zeroCount = 0;
        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            if (zeroCount > k)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }

            if (zeroCount <= k)
            {
                maxCount = max(maxCount, right - left + 1);
            }

            right++;
        }
        return maxCount;
    }
};

//! Sliding Window

/*
> Time Complexity: O(N) + O(N) -> both while loops can traverse at max N
> Space Complexity: O(1)
*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0, maxCount = 0, zeroCount = 0;
        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            while (zeroCount > k)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }

            if (zeroCount <= k)
            {
                maxCount = max(maxCount, right - left + 1);
            }

            right++;
        }
        return maxCount;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int zeroCount = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == 0)
                {
                    zeroCount++;
                }

                if (zeroCount <= k)
                {
                    maxCount = max(maxCount, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxCount;
    }
};
