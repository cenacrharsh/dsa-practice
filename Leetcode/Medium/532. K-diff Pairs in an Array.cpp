#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=r3oiTXIINOU

class Solution
{
public:
 int findPairs(vector<int> &nums, int k)
 {
  int n = nums.size();
  unordered_map<int, int> freq;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
   //! now we update/add arr[i] in the freq array
   if (freq.find(nums[i]) != freq.end())
   {
    freq[nums[i]]++;
   }
   else
   {
    freq[nums[i]] = 1;
   }
  }

  for (auto ele : freq)
  {
   if (k == 0)
   {
    //> if k = 0, we can get difference 0 if the elements themselves occur more than once, eg. 4 - 4 = 0
    if (freq[ele.first] >= 2)
    {
     count++;
    }
   }
   else
   {
    int second_element = ele.first + k;

    if (freq.find(second_element) != freq.end())
    {
     count++;
    }
   }
  }

  return count;
 }
};