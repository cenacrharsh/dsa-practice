#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Priority Queue

class Solution
{
public:
 int largestInteger(int num)
 {
  priority_queue<int> odd;
  priority_queue<int> even;
  string numStr = to_string(num);
  for (int i = 0; i < numStr.size(); i++)
  {
   int n = numStr[i] - '0';
   if (n % 2 == 0)
   {
    even.push(n);
   }
   else
   {
    odd.push(n);
   }
  }
  string ans = "";
  for (int i = 0; i < numStr.size(); i++)
  {
   int n = numStr[i] - '0';
   if (n % 2 == 0)
   {
    ans += to_string(even.top());
    cout << even.top() << endl;
    even.pop();
   }
   else
   {
    ans += to_string(odd.top());
    cout << odd.top() << endl;
    odd.pop();
   }
  }
  return stoi(ans);
 }
};