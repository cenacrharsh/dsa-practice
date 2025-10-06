#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//* TC: O(n/2), SC: O(1)

class Solution
{
public:
    bool isHeap(vector<int> &nums)
    {
        //* to be a min heap, each node must be smaller than it's children
        //* no need to check for leaf nodes as they have no children
        //*  [0 -> n/2 - 1] are the non-leaf nodes
        //* we check from the bottom because as we move up, if we are sure that lower nodes are correct then for upper nodes we don't have to go deep, just checking immediate node is fine

        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if ((leftChild < n && nums[leftChild] < nums[i]) || (rightChild < n && nums[rightChild] < nums[i]))
            {
                return false;
            }
        }
        return true;
    }
};