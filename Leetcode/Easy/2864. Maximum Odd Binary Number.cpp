#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=EUKLOAv4-IQ

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int left = 0, right = 0;
        while (right < s.size())
        {
            if (s[right] == '1')
            {
                swap(s[left], s[right]);
                left++;
            }
            right++;
        }
        swap(s[left - 1], s[s.size() - 1]);
        return s;
    }
};