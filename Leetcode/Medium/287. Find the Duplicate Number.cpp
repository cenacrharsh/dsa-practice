#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

//! Floyd's Tortoise and Hare (Cycle Detection)

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

/*
In phase 1, hare = nums[nums[hare]] is twice as fast as tortoise = nums[tortoise]. Since the hare goes fast, it would be the first to enter the cycle and run around the cycle. At some point, the tortoise enters the cycle as well, and since it's moving slower the hare catches up to the tortoise at some intersection point. Now phase 1 is over, and the tortoise has lost.

Note that the intersection point is not the cycle entrance in the general case.

In phase 2, we give the tortoise a second chance by slowing down the hare, so that it now moves at the speed of tortoise: tortoise = nums[tortoise], hare = nums[hare]. The tortoise is back at the starting position, and the hare starts from the intersection point.
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        //* we can't start both slow & fast from nums[0] without using a do while loop

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

//! Multiply by -1 (Modifies the array)

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = abs(nums[i]);
            if (nums[num] < 0)
            {
                ans = num;
                break;
            }
            nums[num] *= -1;
        }
        return ans;
    }
};

//! Using Hashing

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

//! Using Sorting (Modifies the array)

/*
> Time Complexity: O(N * log(N))
> Space Complexity: O(N)
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i < (nums.size() - 1); i++)
        {
            if (nums[i] == nums[i + 1])
                ans = nums[i];
        }
        return ans;
    }
};

//! Binary Search

/*
Algorithm

We need to find the smallest number such that the count of numbers less than or equal to it is greater than the number itself.

Apply binary search and start with the entire range of numbers [1,n][1,n].

Note: Binary search will be applied to the numbers in the range [1,n] (inclusive) regardless of the contents of the array. So even if a number does not exist in the array, we will still evaluate it. For example, if the array is [1,2,4,2,5][1,2,4,2,5], the algorithm will first evaluate the number 3 even though that number does not exist in the array.
Find the mid-point (curcur).

For curcur, count how many numbers in the input array are less than or equal to it.

If that number strictly exceeds curcur, then store that as the answer and continue to look for a smaller number that satisfies the condition by narrowing the window to the left [low, cur - 1][low,cur−1].
Otherwise, narrow down the window to the right [cur + 1, high][cur+1,high].
Repeat step 3 until we've exhausted the search range (i.e. until lowlow > highhigh) and return the lowest value that met the aforementioned condition.
*/

/*
> Time Complexity: O(n * log n)
> Space Complexity: O(1)
*/

//> Personal Sol

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size(), duplicate = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int count = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= mid)
                {
                    count++;
                }
            }

            if (count > mid)
            {
                duplicate = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return duplicate;
    }
};

//* example: [4,6,4,2,1,4,3,5] -> count(1,2,3,4,5,6,7) = (1,2,3,6,7,8,8)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        // Lambda function to count how many numbers are less than or equal to 'cur'
        auto small_or_equal = [&](int cur)
        {
            int count = 0;
            for (auto &num : nums)
            {
                if (num <= cur)
                    count++;
            }
            return count;
        };

        // 'low' and 'high' represent the range of values of the target
        int low = 1, high = nums.size();
        int duplicate = -1;
        while (low <= high)
        {
            int cur = (low + high) / 2;

            if (small_or_equal(cur) > cur)
            {
                duplicate = cur;
                high = cur - 1;
            }
            else
            {
                low = cur + 1;
            }
        }

        return duplicate;
    }
};