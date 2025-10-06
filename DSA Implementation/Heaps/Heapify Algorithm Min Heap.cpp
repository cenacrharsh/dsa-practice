#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//* TC: O(Log(N)), SC: O(1)

class Solution
{
public:
    //* replace the parent node with it's left or right child whichever is greater
    void heapifyDown(vector<int> &nums, int ind)
    {
        int smallestIndex = ind;
        int leftChild = 2 * ind + 1, rightChild = 2 * ind + 2;

        //* If the left child holds smaller value, update the smallest index
        if (leftChild < nums.size() && nums[leftChild] < nums[smallestIndex])
        {
            smallestIndex = leftChild;
        }

        //* If the right child holds smaller value, update the smallest index
        if (rightChild < nums.size() && nums[rightChild] < nums[smallestIndex])
        {
            smallestIndex = rightChild;
        }

        if (smallestIndex != ind)
        {
            swap(nums[ind], nums[smallestIndex]);
            heapifyDown(nums, smallestIndex);
        }
    }

    //* replace the parent node
    void heapfiyUp(vector<int> &nums, int ind)
    {
        int parentNode = (ind - 1) / 2;

        //* we have not reached the root node
        if (ind > 0)
        {
            //* If current value is smaller than parent
            if (nums[ind] < nums[parentNode])
            {
                swap(nums[ind], nums[parentNode]);

                // Recursively heapify the upper nodes
                heapfiyUp(nums, parentNode);
            }
        }
    }

    void heapify(vector<int> &nums, int ind, int val)
    {
        //* if new value is smaller then original value, in a min heap it would go up, else if greater it goes down
        if (val < nums[ind])
        {
            nums[ind] = val;
            heapfiyUp(nums, ind);
        }
        else
        {
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
    }
};