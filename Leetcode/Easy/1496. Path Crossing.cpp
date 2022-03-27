#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Set of Pairs

class Solution
{
public:
 bool isPathCrossing(string path)
 {
  set<pair<int, int>> coordinates;
  int x = 0;
  int y = 0;
  coordinates.insert({x, y});
  for (char ch : path)
  {
   if (ch == 'N')
   {
    y++;
   }
   else if (ch == 'E')
   {
    x++;
   }
   else if (ch == 'W')
   {
    x--;
   }
   else if (ch == 'S')
   {
    y--;
   }

   cout << x << " " << y << endl;

   if (coordinates.find({x, y}) != coordinates.end())
   {
    return true;
   }

   coordinates.insert({x, y});
  }
  return false;
 }
};