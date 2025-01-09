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
  int prefixCount(vector<string> &words, string pref)
  {
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].substr(0, pref.size()) == pref)
      {
        ans++;
      }
    }
    return ans;
  }
};