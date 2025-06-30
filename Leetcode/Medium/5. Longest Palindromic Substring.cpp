#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 Pointers

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
  string expandFromMiddle(string s, int left, int right)
  {
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
      left--;
      right++;
    }
    return s.substr(left + 1, right - left - 1); //* [right - 1] - [left - 1] + 1, due to while loop we do l++ & r--
  }

  string longestPalindrome(string s)
  {
    if (s.size() < 1)
      return "";

    string maxStr = s.substr(0, 1);
    for (int i = 0; i < s.size() - 1; i++)
    {
      string odd = expandFromMiddle(s, i, i);
      string even = expandFromMiddle(s, i, i + 1);

      if (odd.size() > maxStr.size())
      {
        maxStr = odd;
      }
      if (even.size() > maxStr.size())
      {
        maxStr = even;
      }
    }
    return maxStr;
  }
};