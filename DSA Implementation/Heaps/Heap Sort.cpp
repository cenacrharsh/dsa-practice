#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N) + O(N * Log(N))
> Space Complexity: O()
*/

class Solution
{
private:
    void heapifyDown(vector<int> &nums, int index)
    {
        int largestIndex = index;
        int leftChild = 2 * index + 1, rightChild = 2 * index + 2;

        if (leftChild < nums.size() && nums[leftChild] > nums[largestIndex])
        {
            largestIndex = leftChild;
        }
        if (rightChild < nums.size() && nums[rightChild] > nums[largestIndex])
        {
            largestIndex = rightChild;
        }

        if (largestIndex != index)
        {
            swap(nums[index], nums[largestIndex]);
            heapifyDown(nums, largestIndex);
        }
    }

    void buildMaxHeap(vector<int> &nums)
    {
        //* leaf nodes are already at it's right place
        //* we use heapify down since for both min and max heap, if violations occurs that is smaller element in max heap and greater element in min heap those elements have to move down
        //* fixing downwards also ensures that the subtree starting at node all satisfy the property

        int n = nums.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapifyDown(nums, i);
        }
    }

    void heapifyDownInRange(vector<int> &nums, int lastIndex, int index)
    {
        int largestIndex = index;
        int leftChild = 2 * index + 1, rightChild = 2 * index + 2;

        if (leftChild <= lastIndex && nums[leftChild] > nums[largestIndex])
        {
            largestIndex = leftChild;
        }
        if (rightChild <= lastIndex && nums[rightChild] > nums[largestIndex])
        {
            largestIndex = rightChild;
        }

        if (largestIndex != index)
        {
            swap(nums[index], nums[largestIndex]);
            heapifyDownInRange(nums, lastIndex, largestIndex);
        }
    }

public:
    void heapSort(vector<int> &nums)
    {
        /*
            - Build a max heap from given array
            - Use the extract max functionality
                - We use extract max and swap arr[0] & arr[last]
                - Shrink the array, i.e we now ignore the last index
                - Heapify down arr[0]
                - Stop when last == 0
        */

        buildMaxHeap(nums); //* O(N)
        int lastIndex = nums.size() - 1;
        while (lastIndex > 0) //* O(N)
        {
            swap(nums[0], nums[lastIndex]);
            lastIndex--;
            if (lastIndex > 0)
            {
                heapifyDownInRange(nums, lastIndex, 0); //* O(Log(N))
            }
        }
    }
};