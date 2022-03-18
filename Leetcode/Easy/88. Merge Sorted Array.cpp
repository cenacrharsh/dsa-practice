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
 void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
 {
  vector<int> merged(n + m);
  int i = 0, j = 0, k = 0;
  while (i < m && j < n)
  {
   if (nums1[i] <= nums2[j])
   {
    merged[k++] = nums1[i++];
   }
   else
   {
    merged[k++] = nums2[j++];
   }
  }
  while (i < m)
  {
   merged[k++] = nums1[i++];
  }
  while (j < n)
  {
   merged[k++] = nums2[j++];
  }
  for (i = 0; i < (m + n); i++)
  {
   nums1[i] = merged[i];
  }
 }
};