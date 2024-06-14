#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Nt-WwVzzJqo

//! Counting Sort

/*
> Time Complexity: O(N) + O(K) => K is max element in array
> Space Complexity: O(N) + O(K)
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //* since we need indexes to move the repeated characters ahead make count array of size max element would not help us so to (maxElement + 1) we would add nums.size() so that even if the entire array consists of similar elements even then we would have enough space to move the extra characters ahead
        vector<int> count(*max_element(nums.begin(), nums.end()) + 1 + nums.size(), 0);
        for(int num : nums) {
            count[num]++;
        }

        int ans = 0;
        for(int i = 0; i < count.size(); i++) {
            if(count[i] > 1) {
                int extra = count[i] - 1; //* if freq > 1, except one all others have to be incremented
                count[i + 1] = count[i + 1] + extra;
                ans += extra;
            }
        }
        return ans;
    }
};

//! Sorting

/*
> Time Complexity: O(N * Log(N)) + O(N)
> Space Complexity: O(Log(N)) + O(N)
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //* we'll sort the array then traverse and if we find an element <= to it's prev element we increment it, since we are traversing left to right and incrementing elements even though array is sorted we will find elements < their prev element
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) {
                ans += (nums[i - 1] - nums[i]) + 1; //* we have to make nums[i] > nums[i - 1] hence + 1
                nums[i] += (nums[i - 1] - nums[i]) + 1;
            }
        }
        return ans;
    }
};