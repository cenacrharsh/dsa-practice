#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=S3CJ0dcCXOY

//! Priority Queue

/*
> Time Complexity: O(N * Log(K))
> Space Complexity: O(Log(K))
*/

class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }

    int minDiffViaPQ(vector<int>& nums) {
        priority_queue<int> maxHeap; //* will store smallest 4 elements
        priority_queue<int, vector<int>, greater<int>> minHeap; //* will store largest 4 elements

        for(int num : nums) {
            maxHeap.push(num);
            minHeap.push(num);

            if(maxHeap.size() > 4) {
                maxHeap.pop();
            }
            if(minHeap.size() > 4) {
                minHeap.pop();
            }
        }

        int l = 3, r = nums.size() - 4;
        while(!maxHeap.empty()) {
            //* place first 4 elements of nums
            nums[l--] = maxHeap.top();
            maxHeap.pop();

            //* place last 4 elements of nums
            nums[r++] = minHeap.top();
            minHeap.pop();
        }

        return helper(nums);
    }

    int minDifference(vector<int>& nums) {
        //* to achieve smallest difference b/w minimum and maximum elements we'll sort the elements first then we'll only consider the first 4 and last 4 elements because to achieve min difference we have to change the smallest or largest values
        //* _ _ _ _ .......... _ _ _ _ now we have 4 different choices, either remove first 3 smallest elements in which case diff = arr[n - 1] - arr[3], if we remove first 2 and last element then diff = arr[n - 2] - arr[2], similary we can remove first 1 and last 2 and last 3 elements respectively
        //* be remove we mean out of these 4 options whichever gives us the minimum diff we can achieve that by converting the numbers we removed to any one of the remaining numbers thus effectively minimum and maximum value remaining same in resultant array

        if(nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return minDiffViaPQ(nums);
    }
};

//! Sorting

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(Log(N) + N)
*/

class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }

    int minDifference(vector<int>& nums) {
        //* to achieve smallest difference b/w minimum and maximum elements we'll sort the elements first then we'll only consider the first 4 and last 4 elements because to achieve min difference we have to change the smallest or largest values
        //* _ _ _ _ .......... _ _ _ _ now we have 4 different choices, either remove first 3 smallest elements in which case diff = arr[n - 1] - arr[3], if we remove first 2 and last element then diff = arr[n - 2] - arr[2], similary we can remove first 1 and last 2 and last 3 elements respectively
        //* be remove we mean out of these 4 options whichever gives us the minimum diff we can achieve that by converting the numbers we removed to any one of the remaining numbers thus effectively minimum and maximum value remaining same in resultant array

        if(nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return helper(nums);
    }
};