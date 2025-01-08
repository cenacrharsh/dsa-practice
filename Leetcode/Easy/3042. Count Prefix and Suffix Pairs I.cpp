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
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
      for (int j = i + 1; j < words.size(); j++)
      {
        if (words[i] == words[j].substr(0, words[i].size()) &&
            words[i] == words[j].substr(words[j].size() - words[i].size()))
        {
          ans++;
        }
      }
    }
    return ans;
  }
};