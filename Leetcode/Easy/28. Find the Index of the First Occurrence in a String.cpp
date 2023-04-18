#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        int i = 0;        // to keep track of first matching index, so we can start checking again from i+1 th index in the next traversal
        int j = 0, k = 0; // to traverse the 2 strings
        while (j < n)
        {
            i = j;
            k = 0;
            if (haystack[j] == needle[k])
            {
                while (j < n && k < m && haystack[j] == needle[k])
                {
                    j++;
                    k++;
                }
                if (k == m)
                {
                    return i;
                }
                j = i;
            }
            j++;
        }
        return -1;
    }
};