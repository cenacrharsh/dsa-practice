#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! My Solution

class Solution
{
public:
 static bool sortColWise(vector<int> &v1, vector<int> &v2)
 {
  // sort aq to 2nd column in desc order
  return v1[1] > v2[1];
 }
 int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
 {
  // Displaying the 2D vector before sorting
  int n = boxTypes.size();
  int m = boxTypes[0].size();

  sort(boxTypes.begin(), boxTypes.end(), sortColWise);

  int ans = 0;
  int boxCount = 0;
  for (auto i : boxTypes)
  {
   while (boxCount < truckSize && i[0] > 0)
   {
    boxCount++;
    i[0]--;
    ans += i[1];
   }
  }
  return ans;
 }
};