#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=_YdRjA5EvK4

//! Using Bit Manipulation

/*
> Time Complexity: O(N * 2^N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int xorTotalSum = 0;
        
        //* the j-th bit in the binary representation of i (starting from the least significant bit) indicates whether the j-th element of the set is included.
        //* we generate masks from 0->2^(n-1), and in each mask 0 indicates to not pick the element at that position, eg. 011 => [Skip 2nd Index, Pick 1st Index, Pick 0th Index] => in 123 pick 1 & 2
        for (int subsetMask = 0; subsetMask < (1 << n); subsetMask++) {
            int subsetXorSum = 0;
            for (int j = 0; j < n; j++) {
                //* the expression subsetMask & (1 << j) checks whether the j-th bit of subsetMask is set to 1, this tells us if the j-th element of the set should be included in the current subset.
                if (subsetMask & (1 << j)) {
                    subsetXorSum ^= nums[j];
                }
            }
            xorTotalSum += subsetXorSum;
        }
        return xorTotalSum;
    }
};