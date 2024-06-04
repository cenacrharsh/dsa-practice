#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=gjYSovOESAU

class Solution {
public:
    int longestPalindrome(string s) {
        //* for a valid pallindrome the elements have to occur in pairs
        unordered_map<char, int> freq;
        for(auto c : s)
        {
            freq[c]++;
        }

        int ans = 0;
        bool isOdd = false;
        for(auto [ch, count] : freq)
        {
            if(count % 2 == 0) {
                ans += count;
            } else {
                ans += (count - 1); //* eg. if count = 5, we can still add 4 count in pairs, and leave 1 to add later as part of odd, but since we can only have one odd we'll keep a flag and add +1 at the end
                isOdd = true;
            }
        }
        return isOdd ? ans + 1 : ans;
    }
};