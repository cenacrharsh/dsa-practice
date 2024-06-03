#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=WJaij9ffOIY&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=13

//! Sliding Window

/*
> Time Complexity: O(2N) + O(M)
> Space Complexity: O(N) / O(256)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, count = 0, minLength = INT_MAX, startIndex = -1;
        vector<int> freq(256, 0);
        // unordered_map<char, int> freq; //* char->freq

        //* we are pre-inserting required characters, so a +ve freq indicates that the char is required, and we only increment count when we encounter a freq > 0
        for(int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        while(right < s.size()) {
            if(freq[s[right]] > 0) {
                count++;
            }
            freq[s[right]]--;

            while(count == t.size()) {
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                freq[s[left]]++;
                //* we are removing characters from left and the moment any characters freq becomes > 0 we know that it was an one of the pre-inserted characters and so count decreases
                if(freq[s[left]] > 0) {
                    count--;
                }
                left++;
            }
            right++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};