//# Tutorial: https://www.youtube.com/watch?v=BvKv-118twg&t=14s
//# For Negative Remainder Exlanation: https://www.youtube.com/watch?v=QM0klnvTQzk

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#include <unordered_map>
class Solution
{
public:
 bool canArrange(vector<int> &arr, int k)
 {
  unordered_map<int, int> freqMap;
  for (int i = 0; i < arr.size(); i++)
  {
   int rem = arr[i] % k;
   if (rem < 0)
   {
    rem += k; // Kn-y = Kn'-y+k
   }
   if (freqMap.find(rem) != freqMap.end())
   {
    freqMap[rem] = freqMap[rem] + 1;
   }
   else
   {
    freqMap[rem] = 1;
   }
  }

  for (int i = 0; i < arr.size(); i++)
  {
   int rem = arr[i] % k;
   if (rem < 0)
   {
    rem += k; //* Kn-y = Kn'-y+k
   }

   if (rem == 0)
   {
    int freq = freqMap[rem];
    if (freq % 2 != 0)
    {
     return false;
    }
   }
   else if (2 * rem == k)
   {
    int freq = freqMap[rem];
    if (freq % 2 != 0)
    {
     return false;
    }
   }
   else
   {
    int freq = freqMap[rem];
    int otherFreq;
    if (freqMap.find(k - rem) != freqMap.end())
    {
     otherFreq = freqMap[k - rem];
    }
    else
    {
     otherFreq = 0;
    }
    if (freq != otherFreq)
    {
     return false;
    }
   }
  }
  return true;
 }
};