#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, Modified Merge Sort

/*
> Time Complexity: O(Log N) + O(2 * N) = O(2 * N * Log N) => Division takes Log N + Merge takes N, Merge + Count Pairs both touch every element once
> Space Complexity: O(1) => Original input distorted
*/

class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
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
    }

    //* O(N) = O(N1 + N2), we are not iterating through every element just like during merge
    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2 * (long long)nums[right])
            {
                right++;
            }
            count += (right - (mid + 1)); //* right index itself is not to be included
        }
        return count;
    }

    int mergeSort(vector<int> &nums, int low, int high)
    {
        int count = 0;
        if (low >= high)
        {
            return count;
        }

        int mid = (low + high) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int> &nums)
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
    int reversePairs(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > 2 * (long long)nums[j])
                    count++;
            }
        }
        return count;
    }
};