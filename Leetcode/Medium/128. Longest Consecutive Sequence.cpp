#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
#include <unordered_set>
using namespace std;

//! Brute Force (Loop and use Linear Search)

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/

//! Sorting (Better)

/*
> Time Complexity: O(N * Log N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int longestConsecutiveLength = 0, currCount = 0, lastSmaller = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - 1 == lastSmaller)
            {
                currCount++;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller)
            {
                //* we don't have to do anything if last element is same as current element
                currCount = 1;
                lastSmaller = nums[i];
            }

            longestConsecutiveLength = max(longestConsecutiveLength, currCount);
        }
        return longestConsecutiveLength;
    }
};

//! Unordered Set (Optimal)

/*
> Time Complexity: O(N) + O(2N) ~ Internal while loop takes around 2N not N^2 as we only start from head of seq
> Space Complexity: O(N)
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        // unordered_set<int> st(nums.begin(), nums.end());
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        int longestConsecutiveLength = 1;
        //* iterate over the set instead of array to avoid duplicates
        for (auto num : st)
        {
            //* always check if n-1 exists to avoid calculations mid sequence, always start at the head of the sequence
            if (st.find(num - 1) == st.end())
            {
                int currCount = 1;
                int x = num;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    currCount++;
                }
                longestConsecutiveLength = max(longestConsecutiveLength, currCount);
            }
        }
        return longestConsecutiveLength;
    }
};
