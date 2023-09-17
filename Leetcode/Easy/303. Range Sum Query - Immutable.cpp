#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class NumArray
{
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            prefixSum.push_back(prefixSum[i - 1] + nums[i]);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left - 1];
        // int leftSum = (left - 1) >= 0 ? prefixSum[left - 1] : 0;
        // int rightSum = prefixSum[right];
        // return rightSum - leftSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */