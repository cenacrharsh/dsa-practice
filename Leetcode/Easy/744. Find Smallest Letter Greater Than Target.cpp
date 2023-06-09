#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Binary Search
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        if ((letters[letters.size() - 1] <= target) || (target < letters[0]))
        {
            return letters[0];
        }
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return letters[r];
    }
};