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
public:
    void heapifyDown(vector<int> &nums, int index)
    {
        int smallestIndex = index;
        int leftChild = 2 * index + 1, rightChild = 2 * index + 2;

        if (leftChild < nums.size() && nums[leftChild] < nums[smallestIndex])
        {
            smallestIndex = leftChild;
        }
        if (rightChild < nums.size() && nums[rightChild] < nums[smallestIndex])
        {
            smallestIndex = rightChild;
        }

        if (smallestIndex != index)
        {
            swap(nums[index], nums[smallestIndex]);
            heapifyDown(nums, smallestIndex);
        }
    }

    void buildMinHeap(vector<int> &nums)
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
};