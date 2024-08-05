#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Hashmap

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> freq;
        for (string str : arr)
        {
            freq[str]++;
        }
        for (string str : arr)
        {
            if (freq[str] == 1 && --k == 0)
            {
                return str;
            }
        }
        return "";
    }
};