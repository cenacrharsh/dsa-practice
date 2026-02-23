#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, 2 Pointers + Optimized Sliding Window

/*
> Time Complexity: O(N) + O(1)
> Space Complexity: O(256)
*/

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        unordered_map<int, int> mp;
        int maxLength = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            mp[s[right]]++;

            if (mp.size() > k)
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }

            if (mp.size() <= k)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Better, 2 Pointers + Sliding Window

/*
> Time Complexity: O(N) + O(N) + O(1), O(Log 256) if ordered map
> Space Complexity: O(256)
*/

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        unordered_map<int, int> mp;
        int maxLength = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            mp[s[right]]++;
            while (mp.size() > k)
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }

            if (mp.size() <= k)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};

//! Brute Force, Generate all substrings

/*
> Time Complexity: O(N^2) * O(Log 256) if map, O(1) if unordered_map
> Space Complexity: O(256)
*/
