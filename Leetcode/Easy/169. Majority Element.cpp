// # Tutorial: https://www.youtube.com/watch?v=AoX3BPWNnoE

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Approach 1 - Moore's Voting Algo

/*
> Boyer Moore Voting Algorithm
* If the Majority element was x, and it by any chance appears on the left prefix, then it count at max can be (lenOfLeftPrefix / 2). So since it has to appear more than N/2 times, it is bound to appear as a majority in the last suffix.

# prefix is the left part of array at which point our count = 0, i.e. n(majority) = n(minority) upto this point, hence since majority has to appear > n/2 times, it becomes majority the right parefix or leftover part of array

! only one element can be majority element as only one element can occur more than n/2 times
*/

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ans;

        for (int num : nums)
        {
            if (count == 0)
            {
                ans = num;
                count = 1;
            }
            else if (num == ans)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        // check if it's majority element
        count = 0;
        for (int num : nums)
        {
            if (ans == num)
            {
                count++;
            }
        }

        if (count > nums.size() / 2)
        {
            return ans;
        }

        return -1;
    }
};

//! Approach 2 - Hasmap

/*
> Time Complexity: O(n)/o(n * log n)
> Space Complexity: O(n)
*/

#include <unordered_map>
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int requiredCount = nums.size() / 2;
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for (auto f : freq)
        {
            if (f.second > requiredCount)
            {
                ans = f.first;
            }
        }
        return ans;
    }
};

//! Approach 3

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int maxCount = INT_MIN;
        int ans = -1;
        int i = 0;
        int startVertex = 0;

        while (i < size)
        {
            while (i + 1 < size && nums[i] == nums[i + 1])
            {
                i++;
            }
            int tempCount = i - startVertex + 1;
            if (tempCount > maxCount)
            {
                maxCount = tempCount;
                ans = nums[i];
            }
            startVertex = i + 1;
            i++;
        }

        int requiredCount = size / 2;
        if (maxCount > requiredCount)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};