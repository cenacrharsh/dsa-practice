#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Merge Sort

/*
> Time Complexity: O(N * Log N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
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

    void mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
        {
            return;
        }

        int mid = (low + high) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//! Quick Sort

/*
> Time Complexity: O(N * Log N) ~ Worst O(N^2)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low]; //* assume the first element as pivot element

        int i = low;
        int j = high;

        while (i < j)
        {
            //* find first element greater than pivot on the left, use high - 1 so that after i++ we are still within bounds
            while (nums[i] <= pivot && i <= high - 1)
            {
                i++;
            }

            //* find the first element lower than pivot on the right, use low + 1 so that after i++ we are still within bounds
            while (nums[j] > pivot && j >= low + 1)
            {
                j--;
            }

            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }

        //* swap the pivot with last element of left half
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
        {
            return;
        }

        int partitionIndex = partition(nums, low, high);

        quickSort(nums, 0, partitionIndex - 1);
        quickSort(nums, partitionIndex + 1, high);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//! Randomized Quick Sort

/*
> Time Complexity: O(N * Log N) -> O(N^2) in worst cases
> Space Complexity: O(1)
*/

class Solution
{
public:
    int randomPartition(vector<int> &nums, int l, int r)
    {
        // select random element of array :
        srand(time(NULL));
        int pivot = l + rand() % (r - l);
        swap(nums[pivot], nums[r]);
        return partition(nums, l, r);
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];

        int j = l;

        for (int i = l; i <= r; i++)
        {
            if (nums[i] <= pivot)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j - 1;
    }

    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int pivot_index = randomPartition(nums, l, r);

            quickSort(nums, l, pivot_index - 1);
            quickSort(nums, pivot_index + 1, r);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};