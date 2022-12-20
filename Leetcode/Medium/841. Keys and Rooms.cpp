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
 bool canVisitAllRooms(vector<vector<int>> &rooms)
 {
  int n = rooms.size();
  vector<int> visited(n, 0);
  stack<int> roomIndex;
  roomIndex.push(0);
  while (!roomIndex.empty())
  {
   int currRoomIndex = roomIndex.top();
   roomIndex.pop();
   visited[currRoomIndex] = 1;
   for (auto i : rooms[currRoomIndex])
   {
    if (!visited[i])
     roomIndex.push(i);
   }
  }
  for (auto i : visited)
  {
   if (i == 0)
    return false;
  }
  return true;
 }
};