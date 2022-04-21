#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Sol

class Solution
{
public:
 string digitSum(string s, int k)
 {
  string ans = "";
  int start;
  while (s.size() > k)
  {
   int n = s.size();
   for (start = 0; start < n;)
   {
    string temp;
    if (start + k >= n)
    {
     temp = s.substr(start);
    }
    else
    {
     temp = s.substr(start, k);
    }

    int sum = 0;
    for (int j = 0; j < temp.size(); j++)
    {
     int a = temp[j] - '0';
     sum += a;
    }

    ans += to_string(sum);

    start += k;
   }
   s = ans;
   ans = "";
  }
  return s;
 }
};