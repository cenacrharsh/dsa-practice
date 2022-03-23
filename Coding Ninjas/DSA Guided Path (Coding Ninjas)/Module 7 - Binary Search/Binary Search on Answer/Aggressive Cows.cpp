//# Tutorial: https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=71

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
> Time Complexity: O(n log n)
> Space Complexity: O(1)
*/

bool isPossible(vector<int> &stalls, int k, int minDistance)
{
 int cows = 1;
 int lastStall = stalls[0];
 for (int i = 1; i < stalls.size(); i++)
 {
  if (stalls[i] - lastStall >= minDistance)
  {
   cows++;
   lastStall = stalls[i];
  }

  if (cows == k)
  {
   return true;
  }
 }

 return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
 // Write your code here
 sort(stalls.begin(), stalls.end());
 int n = stalls.size();
 int low = 1;
 int high = stalls[n - 1] - stalls[0];
 int largestMinDistance = -1;

 while (low <= high)
 {
  int minDistance = low + (high - low) / 2;

  if (isPossible(stalls, k, minDistance))
  {
   //! if it's possible to place m cows at minDistance, we inc our search space as it's max distance b/w that we want
   largestMinDistance = minDistance;
   low = minDistance + 1;
  }
  else
  {
   //! if we are unable to place m cows at minDistance then we need to reduce our min distance and try again
   high = minDistance - 1;
  }
 }
 return largestMinDistance;
}

int main()
{
 int n = 10, m = 7;
 vector<int> inp{30, 69, 26, 26, 22, 99, 62, 35, 4, 100};
 int ans = aggressiveCows(inp, m);
 cout << ans << '\n';
}