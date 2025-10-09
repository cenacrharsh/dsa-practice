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
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
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

    vector<int> minToMaxHeap(vector<int> nums)
    {
        //* treat it as normal convertion from array to heap

        //* leaf nodes are already at it's right place
        //* we use heapify down since for both min and max heap, if violations occurs that is smaller element in max heap and greater element in min heap those elements have to move down
        //* fixing downwards also ensures that the subtree starting at node all satisfy the property

        int n = nums.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapifyDown(nums, i);
        }

        return nums;
    }
};