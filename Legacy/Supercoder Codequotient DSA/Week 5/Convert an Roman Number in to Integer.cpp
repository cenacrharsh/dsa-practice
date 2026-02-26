#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_map>

int romanToInt(string a)
{
 unordered_map<char, int> roman;
 roman.insert(make_pair('I', 1));
 roman.insert(make_pair('V', 5));
 roman.insert(make_pair('X', 10));
 roman.insert(make_pair('L', 50));
 roman.insert(make_pair('C', 100));
 roman.insert(make_pair('D', 500));
 roman.insert(make_pair('M', 1000));

 int n = a.size();
 int sum = 0;
 int num = 0;

 for (int i = 0; i < n;)
 {
  if (i == (n - 1) || (roman[a[i]] >= roman[a[i + 1]]))
  {
   num = roman[a[i]];
   i++;
  }
  else
  {
   num = roman[a[i + 1]] - roman[a[i]];
   i = i + 2;
  }
  sum += num;
 }
 return sum;
}