#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_set>
bool pairSum(vector<int> arr, int n, int k)
{
 // Write your code here
 unordered_set<int> character;
 for (int n : arr)
 {
  int b = k - n;
  if (character.find(b) != character.end())
  {
   return true;
  }
  character.insert(n);
 }
 return false;
}
