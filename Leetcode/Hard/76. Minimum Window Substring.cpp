#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal, Sliding Window

/*
> Time Complexity: O(M) + O(2 * N)
> Space Complexity: O(256)
*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(256, 0);
        for (int i = 0; i < t.size(); i++)
        {
            freq[t[i]]++;
        }

        int left = 0, right = 0, count = 0, startIndex = -1, minLen = INT_MAX;
        while (right < s.size())
        {
            if (freq[s[right]] > 0)
            {
                count++;
            }
            freq[s[right]]--;

            while (count == t.size())
            {
                if (right - left + 1 < minLen)
                {
                    minLen = min(minLen, right - left + 1);
                    startIndex = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
            right++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(256)
*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int minLen = 1e9;
        int startIndex = -1;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(256, 0);
            int count = 0;
            for (int j = 0; j < t.size(); j++)
            {
                freq[t[j]]++;
            }

            for (int j = i; j < s.size(); j++)
            {
                if (freq[s[j]] > 0)
                {
                    count++;
                }

                freq[s[j]]--;

                if (count == t.size())
                {
                    if (j - i + 1 < minLen)
                    {
                        minLen = min(minLen, (j - i + 1));
                        startIndex = i;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};