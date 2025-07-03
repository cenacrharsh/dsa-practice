#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Recursive

class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";

    string prev = countAndSay(n - 1);
    string ans = "";
    int count = 1, i = 1;
    for (i = 1; i < prev.size(); i++)
    {
      if (prev[i] == prev[i - 1])
      {
        count++;
      }
      else
      {
        //* add freq first then character
        ans += count + '0';
        ans += prev[i - 1];
        count = 1;
      }
    }
    //* to take care of last set of digits as loop ends without ever adding them to the result
    ans += count + '0';
    ans += prev[i - 1];

    return ans;
  }
};

//! Iterative

class Solution
{
public:
  vector<pair<int, int>> helper1(string s)
  {
    vector<pair<int, int>> temp;
    int i = 0, j = 0;
    while (j < s.size())
    {
      while (j < s.size() && s[j] == s[i])
      {
        j++;
      }
      int count = j - i;
      temp.push_back({s[i] - '0', count});
      i = j;
    }
    return temp;
  }

  string helper2(vector<pair<int, int>> v)
  {
    string temp = "";
    for (int i = 0; i < v.size(); i++)
    {
      temp += to_string(v[i].second) + to_string(v[i].first);
    }
    return temp;
  }

  string countAndSay(int n)
  {
    vector<pair<int, int>> part1;
    string part2 = "1";
    for (int i = 0; i < n - 1; i++)
    {
      part1 = helper1(part2);
      part2 = helper2(part1);
    }
    return part2;
  }
};