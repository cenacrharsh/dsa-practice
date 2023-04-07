#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Adding 32

class Solution
{
public:
    string toLowerCase(string s)
    {
        // A : 65, a : 97
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
                //* s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
};

//* or

class Solution
{
public:
    string toLowerCase(string s)
    {
        //* A : 65, a : 97
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))
            {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};