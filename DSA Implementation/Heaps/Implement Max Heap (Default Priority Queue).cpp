#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
private:
    vector<int> arr; // dynamic array to store the max heap
    int count;       // count variable to store the number of variables in max heap

    //* replace the parent node with it's left or right child whichever is greater, or recursively heapfiy downwards
    void heapifyDown(vector<int> &nums, int ind)
    {
        int largestIndex = ind;
        int leftChild = 2 * ind + 1, rightChild = 2 * ind + 2;

        //* If the left child holds larger value, update the largest index
        if (leftChild < nums.size() && nums[leftChild] > nums[largestIndex])
        {
            largestIndex = leftChild;
        }

        //* If the right child holds larger value, update the largest index
        if (rightChild < nums.size() && nums[rightChild] > nums[largestIndex])
        {
            largestIndex = rightChild;
        }

        if (largestIndex != ind)
        {
            swap(nums[ind], nums[largestIndex]);
            heapifyDown(nums, largestIndex);
        }
    }

    //* replace the parent node, or recursively heapify upwards
    void heapfiyUp(vector<int> &nums, int ind)
    {
        int parentNode = (ind - 1) / 2;

        //* we have not reached the root node
        if (ind > 0)
        {
            //* if current value is larger than parent
            if (nums[ind] > nums[parentNode])
            {
                // swap the values at the two indices
                swap(nums[ind], nums[parentNode]);

                // recursively heapify the upper nodes
                heapfiyUp(nums, parentNode);
            }
        }
    }

public:
    // Initialize the max heap data structure
    void initializeHeap()
    {
        arr.clear();
        count = 0;
    }

    // Insert given values inside max heap
    void insert(int key)
    {
        // insert the value at the end of the array
        arr.push_back(key);

        // heapify updwards, because new value can be > it's parent
        heapfiyUp(arr, count); // count keeps track of current index
        count = count + 1;

        return;
    }

    // Change the value at the given index in max heap
    void changeKey(int index, int new_val)
    {
        // if the new value is larger than the existing value, we heapfiyUp since it can be greater than it's parent
        if (new_val > arr[index])
        {
            arr[index] = new_val;
            heapfiyUp(arr, index);
        }
        // if the new value is smaller than the existing value, we heapifyDown, since it can be smaller than it's children
        else
        {
            arr[index] = new_val;
            heapifyDown(arr, index);
        }
    }

    // Extract max value from max heap
    void extractMax()
    {
        int maxElement = arr[0]; // max value in the heap

        // swap the largest value with the value at last index
        swap(arr[0], arr[count - 1]);

        // remove the maximum value from the array
        arr.pop_back();
        count = count - 1;

        // heapify the root value downwards since it has been replaced by a smaller value
        heapifyDown(arr, 0);
    }

    bool isEmpty()
    {
        return (count == 0);
    }

    int getMax()
    {
        // the value stored at root of max heap is the greatest
        return arr[0];
    }

    int heapSize()
    {
        return count;
    }
};