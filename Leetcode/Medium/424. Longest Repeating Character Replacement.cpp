#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial - https://www.youtube.com/watch?v=_eNhaDCr6P0&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=9

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        //* when we already have a len - maxFreq <= k, now upon going further we don't need to go for lower values of maxFreq as to inc len further we need to go higher and if go higher to satisfy the equation len - maxFreq <= k, maxFreq also has to go higher so going lower is never going to help us get higher maxLen

        vector<int> freq(26, 0);
        int maxFreq = INT_MIN, maxLen = INT_MIN;
        int left = 0, right = 0;
        while(right < s.size()) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            if((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

//! Sliding Window

/*
> Time Complexity: O(N + N) * 26
> Space Complexity: O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxFreq = INT_MIN, maxLen = INT_MIN;
        int left = 0, right = 0;
        while(right < s.size()) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                maxFreq = 0;
                for(int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
                left++;
            }

            if((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(26)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int maxFreq = INT_MIN, maxLen = INT_MIN;
        for(int i = 0; i < s.size(); i++) {
            hash.assign(26, 0);
            for(int j = i; j < s.size(); j++) {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);

                int changes = (j - i + 1) - maxFreq;
                if(changes <= k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxLen;
    }
};


