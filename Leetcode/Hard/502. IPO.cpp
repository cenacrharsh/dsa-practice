#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=m4mwEPsCJvg

class Solution
{
public:
 static bool cmp(pair<int, int> &a, pair<int, int> &b)
 {
  if (a.second != b.second)
  {
   return a.second < b.second;
  }
  return a.first < a.second;
 }

 int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
 {
  // max heap ordered by first element
  int n = profits.size();
  vector<pair<int, int>> projects(n);
  for (int i = 0; i < n; i++)
  {
   projects[i] = {profits[i], capital[i]};
  }
  sort(projects.begin(), projects.end(), cmp);
  int i = 0;
  priority_queue<int> pq;
  while (k--)
  {
   // push profits of all projects in pq whose capital is <= w
   while (i < n && projects[i].second <= w)
   {
    pq.push(projects[i].first);
    i++;
   }
   // add to w the project with max profit if there is any
   if (!pq.empty())
   {
    w += pq.top();
    pq.pop();
   }
  }
  return w;
 }
};