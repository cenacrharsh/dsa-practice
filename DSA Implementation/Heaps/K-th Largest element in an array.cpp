#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Quick Select & Partition

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right)
    {
        // get the pivot index
        int pivot = nums[pivotIndex];

        // move the pivotIndex to the leftmost element
        swap(nums[left], nums[pivotIndex]);

        // index to track the start of the right portion
        int index = left + 1;

        for (int i = left + 1; i <= right; i++)
        {
            // if the current element is greater than the pivot
            if (nums[i] > pivot)
            {
                // place the current element in the left portion of the array
                swap(nums[index], nums[i]);

                // move the right portion index
                index++;
            }
        }

        // place the pivotIndex element in the middle
        swap(nums[left], nums[index - 1]);

        return index - 1;
    }

    int kthLargestElement(vector<int> &nums, int k)
    {
        /*
            - quick select and partition
            - we divide the array into 3 portions: Left - Random Id - Right
            - all the elements to the left should be greater than arr[Random Id] and all the elements to the right should be smaller than arr[Random Id]
            - then on value of K we decide we have to eliminate which part of the array
        */
        int left = 0, right = nums.size() - 1;
        while (true)
        {
            // randomly choose a pivot index between left and right
            int pivotIndex = (rand() % (right - left + 1)) + left;

            // update the pivot index
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);

            //* after partition kth largest element will be present at index k - 1 since we go with 0 based indexing
            if (pivotIndex == k - 1)
            {
                return nums[pivotIndex];
            }
            else if (k - 1 < pivotIndex)
            {
                right = pivotIndex + 1;
            }
            else
            {
                left = pivotIndex + 1;
            }
        }
    }
};

//! Min Priority Queue

/*
> Time Complexity: O(K * Log(K)) + O((N - K) * Log(K)) -> O(N * Log(K))
> Space Complexity: O(K)
*/

class Solution
{
public:
    int kthLargestElement(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int i = 0; i <= k - 1; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            // insert only if current element is > smallest element in priority queue
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};