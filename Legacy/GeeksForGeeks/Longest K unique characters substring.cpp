#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=teM9ZsVRQyc&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=6

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int left = 0, right = 0, maxLen = -1;
        unordered_map<char, int> freq; //* char->freq
        while(right < s.size()) {
            freq[s[right]]++;
            
            if(freq.size() > k) {
                freq[s[left]]--;
                if(freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            
            if(freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};