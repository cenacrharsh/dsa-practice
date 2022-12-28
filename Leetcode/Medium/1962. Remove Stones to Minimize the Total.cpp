#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=ysvYRJP0E6o

class Solution
{
public:
 int minStoneSum(vector<int> &piles, int k)
 {
  priority_queue<int> q(piles.begin(), piles.end());
  // for(int i = 0; i < piles.size(); i++)
  // {
  //     q.push(piles[i]);
  // }
  int ans = accumulate(piles.begin(), piles.end(), 0);
  while (k--)
  {
   int maxElement = q.top();
   q.pop();
   int temp = maxElement / 2;
   q.push(maxElement - temp);
   ans -= temp;
  }
  // int ans = 0;
  // while(!q.empty())
  // {
  //     ans += q.top();
  //     q.pop();
  // }
  return ans;
 }
};