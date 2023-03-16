#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 2 pointers
class Solution
{
public:
 void reverseString(vector<char> &s)
 {
  int l = 0, r = s.size() - 1;
  while (l < r)
  {
   // cout << "swapping: " << s[l] << " and " << s[r] << endl;
   swap(s[l], s[r]);
   l++;
   r--;
  }
 }
};