#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=318hrWVr_5U

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int minimumLength(string s)
    {
        if (s.size() == 1)
        {
            return 1;
        }
        int left = 0, right = s.size() - 1;
        int ans = s.size();
        while (left < right && s[left] == s[right])
        {
            char currChar = s[left];
            while (left <= right && s[left] == currChar)
            {
                left++;
            }
            while (left <= right && s[right] == currChar)
            {
                right--;
            }
        }
        return (right - left + 1); //* return length of window left
    }
};