#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Max Heap

class Solution
{
public:
 int secondHighest(string s)
 {
  priority_queue<int> max_heap;
  for (char ch : s)
  {
   if (isdigit(ch))
   {
    max_heap.push(ch - '0');
   }
  }
  int second_largest = -1;
  if (!max_heap.empty())
  {
   int largest = max_heap.top();
   while (!max_heap.empty())
   {
    if (max_heap.top() != largest)
    {
     second_largest = max_heap.top();
     break;
    }
    max_heap.pop();
   }
  }
  return second_largest;
 }
};