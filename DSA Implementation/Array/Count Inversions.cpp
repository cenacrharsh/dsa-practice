#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal

/*
> Time Complexity: O(N * Log N)
> Space Complexity: O(N) => We are altering the origianl array, if not then create extra copy
*/

class Solution
{
public:
    long long merge(vector<int> &nums, int low, int mid, int high)
    {
        long long count = 0;
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                //* this part tells that element in the right is lesser that element in the left
                count += (mid - left + 1); //* if nums[right] is < nums[left] then it's < all the elements present in the array after left index since array is sorted, so count of inversion pairs we get is (mid - left + 1)
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSort(vector<int> &nums, int low, int high)
    {
        long long count = 0;
        if (low >= high)
        {
            return count;
        }

        int mid = (low + high) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
        return count;
    }

    long long int numberOfInversions(vector<int> nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
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
    long long int numberOfInversions(vector<int> nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};