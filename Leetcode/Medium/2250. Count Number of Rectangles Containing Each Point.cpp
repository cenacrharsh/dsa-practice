#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Binary Search

class Solution
{
public:
 vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
 {
  vector<vector<int>> coordinates(101); // coordinates[y] = vector of all x coordinates

  for (int i = 0; i < rectangles.size(); i++)
  {
   int x = rectangles[i][0];
   int y = rectangles[i][1];

   coordinates[y].push_back(x);
  }

  // sorting all vectors with x-coordintes
  for (int i = 1; i <= 100; i++)
  {
   sort(coordinates[i].begin(), coordinates[i].end());
  }

  vector<int> ans;
  for (int i = 0; i < points.size(); i++)
  {
   int count = 0;
   int x = points[i][0];
   int y = points[i][1];
   for (int j = y; j <= 100; j++)
   {
    // find the index of first number >= x
    int id = lower_bound(coordinates[j].begin(), coordinates[j].end(), x) - coordinates[j].begin();

    // add all numbers >= x to our count
    count += (coordinates[j].size() - id);
   }
   ans.push_back(count);
  }
  return ans;
 }
};