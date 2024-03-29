#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Sliding Window

// # Tutorial: https://www.youtube.com/watch?v=CZ-z1ViskzE

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long count = 0, ans = 0;
        int left = 0, right = 0;
        //* we find the index where we have k occurences of max element and then we count all subarrays ending at that index in our answer, for eg. in [1,3,2,3,3] window [3,3] is valid so all elements in front extending all the way to the beginning are valid as well
        //* we have 2 cases, one where count > k so we keep decrementing window unless we have k occurences only, other when count == k but element at left != maxElement so we can remove it from our window, code: while(count > k || (left <= right && count == k && nums[left] != maxElement))
        while (right < nums.size())
        {
            if (nums[right] == maxElement)
            {
                count++;
            }

            while (count > k || (left <= right && count == k && nums[left] != maxElement))
            {
                if (nums[left] == maxElement)
                {
                    count--;
                }
                left++;
            }

            if (count == k)
            {
                ans += left + 1; //* all indexes from 0->left are valid subarrays
            }

            right++;
        }
        return ans;
    }
};