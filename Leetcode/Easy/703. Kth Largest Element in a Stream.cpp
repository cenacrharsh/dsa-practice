#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=0tFmP1Eiilg

//! Using Min Priority Queue

/*
* Time complexity:
Construction: O(N * logK)
Adding: O(logK)

* Space Complexity:
O(K) (can be reduced to O(1) by reusing memory of the existing array
*/

class KthLargest
{
public:
    //* we'll use a min heap if we need Kth largest element
    //* we need to maintain the size of the heap == k, so that Kth largest element is always at top

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);

            if (minHeap.size() > size)
            {
                minHeap.pop();
            }
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > size)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */