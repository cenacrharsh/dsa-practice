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
    vector<int> arr;
    int count;

    //* replace the parent node with it's left or right child whichever is greater, or recursively heapfiy downwards
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

    //* replace the parent node, or recursively heapify upwards
    void heapfiyUp(vector<int> &nums, int ind)
    {
        int parentNode = (ind - 1) / 2;

        //* we have not reached the root node
        if (ind > 0)
        {
            //* if current value is larger than parent
            if (nums[ind] < nums[parentNode])
            {
                // swap the values at the two indices
                swap(nums[ind], nums[parentNode]);

                // recursively heapify the upper nodes
                heapfiyUp(nums, parentNode);
            }
        }
    }

public:
    // Initialize the min heap data structure
    void initializeHeap()
    {
        arr.clear();
        count = 0;
    }

    // Insert given values inside min heap
    void insert(int key)
    {
        // insert the value at the end of the array
        arr.push_back(key);

        // heapify upwards because new value can < it's parent
        heapfiyUp(arr, count);
        count = count + 1;

        return;
    }

    // Change the value at the given index in min heap
    void changeKey(int index, int new_val)
    {
        // if the new value is smaller than existing value, then we heapify up since it can also be smaller than it's parent
        if (new_val < arr[index])
        {
            arr[index] = new_val;
            heapfiyUp(arr, index);
        }
        // if the new value is larger than existing value, we heapify down since it can be larger than it's children
        else
        {
            arr[index] = new_val;
            heapifyDown(arr, index);
        }
    }

    void extractMin()
    {
        int minElement = arr[0];

        // swap the smallest value with the value at the last index
        swap(arr[0], arr[count - 1]);

        // remove the min value from the array
        arr.pop_back();
        count = count - 1;

        // heapify the root value downwards since it has been replaced by a larger value
        heapifyDown(arr, 0);
    }

    bool isEmpty()
    {
        return (count == 0);
    }

    int getMin()
    {
        // the value stored at root of min heap is the smallest
        return arr[0];
    }

    int heapSize()
    {
        return count;
    }
};