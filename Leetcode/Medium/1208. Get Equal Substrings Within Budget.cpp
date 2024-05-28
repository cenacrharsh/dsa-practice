#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //* longest substring with at most cost as maxCost
        int left = 0, right = 0, maxLen = INT_MIN, cost = 0;
        while(right < s.size()) {
            cost += abs(s[right] - t[right]);

            if(cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            if(cost <= maxCost) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

//! Sliding Window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //* longest substring with at most cost as maxCost
        int left = 0, right = 0, maxLen = INT_MIN, cost = 0;
        while(right < s.size()) {
            cost += abs(s[right] - t[right]);

            while(cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};