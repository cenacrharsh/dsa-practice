#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//* sorting is done bottom to top in heap tree/left to right in array => so if max heap which uses less func by default, we return true if lhs < rhs because we build from bottom that is if keep setting lowest elements first then higher elements automatically

/* We will see the ordering from bottom to top. So, if i say that the order is ascending then it means that the smaller elements will be at the bottom and the higher elements will be at the top. (I'm taking tree representation of the heap, if you consider array representation then the higher values will be at right and lower at the left)
 */
class myComparator
{
public:
 bool operator()(const pair<int, string> &p1,
                 const pair<int, string> &p2)
 {
  if (p1.first == p2.first)
   return p1.second < p2.second;
  return p1.first > p2.first;
 }
};

class Solution
{
public:
 vector<string> topKFrequent(vector<string> &words, int k)
 {
  unordered_map<string, int> freq;
  for (auto it : words)
  {
   freq[it]++;
  }
  // min priority queue
  priority_queue<pair<int, string>,
                 vector<pair<int, string>>,
                 myComparator>
      pq;
  for (auto it : freq)
  {
   string word = it.first;
   int wordFreq = it.second;
   pq.push({wordFreq, word});
   // when size of pq exceeds k, we pop word with least freq
   if (pq.size() > k)
   {
    pq.pop();
   }
  }
  vector<string> ans;
  while (!pq.empty())
  {
   ans.insert(ans.begin(), (pq.top().second));
   pq.pop();
  }
  return ans;
 }
};