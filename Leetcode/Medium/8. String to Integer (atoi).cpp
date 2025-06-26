#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  int myAtoi(string s)
  {
    long ans = 0; //* to safely handle and check if overflow occurs
    int idx = 0, n = s.size();
    bool negative = false;

    //* skip leading whitespaces
    while (idx < n && s[idx] == ' ')
      idx++;

    //* check of + or - sign
    if (s[idx] == '-')
    {
      negative = true;
      idx++;
    }
    else if (s[idx] == '+')
    {
      idx++;
    }

    while (idx < s.size() && isdigit(s[idx]))
    {
      int digit = s[idx] - '0';
      ans = (ans * 10) + digit;

      //* check overflow
      if (negative && -ans <= INT_MIN)
      {
        return INT_MIN;
      }
      else if (!negative && ans >= INT_MAX)
      {
        return INT_MAX;
      }
      idx++;
    }

    return negative ? -ans : ans;
  }
};