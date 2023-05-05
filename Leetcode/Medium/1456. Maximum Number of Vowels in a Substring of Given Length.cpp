#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Sliding Window

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        string subString = "";
        int vowelCount = 0;
        int maxCount = 0;
        int l = 0, r = 0;
        while (r < s.size())
        {
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')
            {
                vowelCount++;
            }
            int len = r - l + 1;
            if (len > k)
            {
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                {
                    vowelCount--;
                }
                l++;
            }
            maxCount = max(maxCount, vowelCount);
            r++;
        }
        return maxCount;
    }
};