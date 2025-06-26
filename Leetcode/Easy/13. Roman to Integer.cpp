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
  int romanToInt(string s)
  {
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int sum = 0, num = 0;
    for (int i = 0; i < s.size();)
    {
      //* if current digit >= next digit or it's the last digit
      if (i == s.size() - 1 || mp[s[i]] >= mp[s[i + 1]])
      {
        num = mp[s[i]];
        i++;
      }
      //* if current digit is < next digit
      else
      {
        num = mp[s[i + 1]] - mp[s[i]];
        i += 2;
      }
      sum += num;
    }
    return sum;
  }
};