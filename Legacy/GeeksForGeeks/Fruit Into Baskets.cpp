#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=e3bs0uA1NhQ&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=8

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
    public:
    int totalFruits(int N, vector<int> &fruits) {
        //* max length subarray with at most 2 types of fruits
        unordered_map<int, int> freq; //* tree type->num fruits of that type
        int left = 0, right = 0, maxCount = INT_MIN;
        while(right < fruits.size()) {
            freq[fruits[right]]++;
            
            if(freq.size() > 2) {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }
            
            if(freq.size() <= 2) {
                maxCount = max(maxCount, right - left + 1);
            }
            right++;
        }
        return maxCount;
    }
};

