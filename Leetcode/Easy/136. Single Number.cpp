#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Bitwise Operator XOR (^)

// # Tutorial: https://www.youtube.com/watch?v=sFBCAl8yBfE&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=5

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(int i = 0; i < nums.size(); i++) {
            XOR ^= nums[i];
        }
        return XOR;
    }
};