#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 vector<int> sortEvenOdd(vector<int> &nums)
 {
  int n = nums.size();
  vector<int> odd;
  vector<int> even;
  for (int i = 0; i < nums.size(); i++)
  {
   if (i % 2 == 0)
   {
    even.push_back(nums[i]);
   }
   else
   {
    odd.push_back(nums[i]);
   }
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), greater<int>());

  vector<int> ans(n);
  int j = 0;
  for (int i = 0; i < even.size(); i++)
  {
   ans[j] = even[i];
   j += 2;
  }
  j = 1;
  for (int i = 0; i < odd.size(); i++)
  {
   ans[j] = odd[i];
   j += 2;
  }

  return ans;
 }
};