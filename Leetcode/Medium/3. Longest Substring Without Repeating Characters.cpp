#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=-zSxTJkcdAo&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=3

//! Using Freq Array

/*
> Time Complexity: O(N)
> Space Complexity: O(256)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int left = 0, right = 0, maxLen = 0;
        while(right < s.size()) {
            while(freq[s[right]] != 0) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            freq[s[right]]++;
            right++;
        }
        return maxLen;
    }
};

//! Using Hashmap

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> freq; //* char->index
        int left = 0, right = 0, maxLen = 0;
        while(right < s.size()) {
            while(freq.find(s[right]) != freq.end()) {
                freq[s[left]]--;
                if(freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            freq[s[right]]++;
            right++;
        }
        return maxLen;
    }
};