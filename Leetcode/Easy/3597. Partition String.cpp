#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;

class Solution
{
public:
  vector<string> partitionString(string s)
  {
    unordered_set<string> mp;
    string temp = "";
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
      temp += s[i];

      if (mp.find(temp) == mp.end())
      {
        ans.push_back(temp);
        mp.insert(temp);
        temp = "";
      }
    }
    return ans;
  }
};