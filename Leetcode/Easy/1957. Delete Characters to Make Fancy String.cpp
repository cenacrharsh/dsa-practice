#include <bits/stdc++.h>
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
  string makeFancyString(string s)
  {
    if (s.size() <= 2)
    {
      return s;
    }
    string ans = s.substr(0, 2);
    for (int i = 2; i < s.size(); i++)
    {
      if (s[i] != s[i - 1] || s[i] != s[i - 2])
      {
        ans += s[i];
      }
    }
    return ans;
  }
};