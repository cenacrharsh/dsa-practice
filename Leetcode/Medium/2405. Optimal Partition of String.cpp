#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Freq Vector
class Solution
{
public:
    int partitionString(string s)
    {
        int count = 0;
        for (int i = 0; i <= s.length() - 1; i++)
        {
            bool unique = true;
            int freq[26] = {0};
            while (unique && (i <= s.length() - 1))
            {
                if (freq[s[i] - 'a'] == 0)
                {
                    freq[s[i] - 'a']++;
                    i++;
                }
                else
                {
                    count++;
                    i--;
                    unique = false;
                }
            }
        }
        return ++count;
    }
};

//! Using Set
class Solution
{
public:
    int partitionString(string s)
    {
        int count = 0;
        for (int i = 0; i <= s.length() - 1; i++)
        {
            unordered_set<char> unique;
            while (i <= s.length() - 1)
            {
                if (unique.find(s[i]) == unique.end())
                {
                    unique.insert(s[i]);
                    i++;
                }
                else
                {
                    count++;
                    i--;
                    break;
                }
            }
        }
        // to count the last unique string
        return ++count;
    }
};