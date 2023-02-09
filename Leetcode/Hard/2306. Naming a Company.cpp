#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*26)
*/

class Solution
{
public:
 long long distinctNames(vector<string> &ideas)
 {
  long long disName = 0;
  vector<unordered_set<string>> arr(26);
  // a -> pple, xe | b -> at, all.....
  for (string s : ideas)
  {
   arr[s[0] - 'a'].insert(s.substr(1));
  }

  for (int i = 0; i < 25; i++)
  {
   for (int j = i + 1; j < 26; j++)
   {
    unordered_set<string> set;
    set.insert(arr[i].begin(), arr[i].end());
    set.insert(arr[j].begin(), arr[j].end());
    disName += (set.size() - arr[i].size()) * (set.size() - arr[j].size());
    // set.size() - arr[i].size() => gives number of distinct strings arr[j], if a distince strings in arr[i] and b distinct strings in arr[j], then total combinations possible in a*b, also *2 in final ans makes sure we account for b*a as well
   }
  }
  return disName * 2;
  // *2 to make sure we include both cases, eg. if ab is vaild then ba is also valid
 }
};