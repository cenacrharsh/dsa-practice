#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointers
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }
        int left = 0, right = s1.size() - 1;
        while (s1[left] == s2[left])
        {
            left++;
        }
        while (s1[right] == s2[right])
        {
            right--;
        }
        swap(s1[left], s1[right]);
        return s1 == s2;
    }
};

//! Using Freq Vector
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> freq1(26, 0);
        for (auto str : s1)
        {
            freq1[str - 'a']++;
        }
        for (auto str : s2)
        {
            freq1[str - 'a']--;
        }
        for (auto it : freq1)
        {
            if (it != 0)
            {
                return false;
            }
        }
        int count = 0;
        int len = s1.size();
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
            }
        }
        return count > 2 ? false : true;
    }
};