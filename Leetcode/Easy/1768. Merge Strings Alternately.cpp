#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 1 pointer

/*
> Time Complexity: O(N + M)
> Space Complexity: O(1)
*/

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        int i = 0;
        string ans = "";
        while (i < l1 || i < l2)
        {
            if (i < l1)
            {
                ans += word1[i];
            }
            if (i < l2)
            {
                ans += word2[i];
            }
            i++;
        }
        return ans;
    }
};

//! 2 pointers

/*
> Time Complexity: O(N + M)
> Space Complexity: O(1)
*/

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        int i = 0, j = 0;
        string ans = "";
        while (i < l1 || j < l2)
        {
            if (i < l1)
            {
                ans += word1[i++];
            }
            if (j < l2)
            {
                ans += word2[j++];
            }
        }
        return ans;
    }
};

//* or

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        int i = 0, j = 0;
        string ans = "";
        while (i < l1 && j < l2)
        {
            ans += word1[i++];
            ans += word2[j++];
        }
        while (i < l1)
        {
            ans += word1[i++];
        }
        while (j < l2)
        {
            ans += word2[j++];
        }
        return ans;
    }
};