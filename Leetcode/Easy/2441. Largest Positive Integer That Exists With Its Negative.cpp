#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=LZaWj13_D6o

//! 1 Pass Using Hashmap

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> um;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(um.find(-nums[i]) != um.end()) {
                ans = max(ans, abs(nums[i])); //* -nums[i] works for both +ve and -ve numbers as -(-n) == n so we can simply search for the the -ve of whatever number we have currently and for ans since we need +ve so we'll use abs(nums[i])
            }
            um[nums[i]]++;
        }
        return ans;
    }
};

//! 2 Pointers and Sorting

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(Log(N))
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(-nums[left] == nums[right]) {
                return nums[right]; //* no need to go further as values will only decrease
            } else if(-nums[left] > nums[right]) {
                left++; //* we might still encounter a smaller value which will be equal to nums[j]
            } else {
                right--; //* if nums[i] is smaller, numbers to right of i will be smaller still so we need smaller values from right so j--
            }
        }
        return -1;
    }
};