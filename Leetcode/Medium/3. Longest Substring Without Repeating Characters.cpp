#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, 2 Pointer + Sliding Window + Using Freq Array

/*
> Time Complexity: O()
> Space Complexity: O()
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = 0;
        vector<int> freq(256, -1);
        while (right < s.size())
        {
            if (freq[s[right]] != -1)
            {
                //* even if element present in hashmap if it's out of the left->right substring it doesn't matter
                if (freq[s[right]] >= left)
                {
                    left = freq[s[right]] + 1; //* if current char is found at index freq[s[right]] we go to one index ahead
                }
            }

            freq[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

/*
> Time Complexity: ~ O(2N)
> Space Complexity: O(256)
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> freq(256); //* there are 256 different characters
        while (right < s.size())
        {
            while (freq[s[right]] != 0)
            {
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

//! Optimal, 2 Pointer + Slidng Window + Using Hashmap

/*
> Time Complexity: ~ O(2N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;
        while (right < s.size())
        {
            while (mp[s[right]] != 0)
            {
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            mp[s[right]]++;
            right++;
        }
        return maxLen;
    }
};

//! Brute Force, Generate all substrings

/*
> Time Complexity: O(N^2)
> Space Complexity: O(256)
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(256, 0);
            for (int j = i; j < s.size(); j++)
            {
                if (freq[s[j]] == 1)
                {
                    break;
                }

                freq[s[j]] = 1;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};