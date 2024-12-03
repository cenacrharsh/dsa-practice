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
  string addSpaces(string s, vector<int> &spaces)
  {
    int n = s.size();
    int m = spaces.size();
    string ans(n + m, ' ');
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      if (j < m && i == spaces[j])
      {
        j++;
      }
      ans[i + j] = s[i];
    }
    return ans;
  }
};