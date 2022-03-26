#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int leastFavorite(int favorites[], int n)
{
 // Write your code here
 unordered_map<int, int> freq;
 int leastFavFreq = INT_MAX;
 int greatestLeastFav = INT_MIN;
 for (int i = 0; i < n; i++)
 {
  if (freq.find(favorites[i]) != freq.end())
  {
   freq[favorites[i]]++;
  }
  else
  {
   freq[favorites[i]] = 1;
  }
 }
 for (auto i : freq)
 {
  if (i.second <= leastFavFreq)
  {
   leastFavFreq = i.second;
  }
 }
 for (auto i : freq)
 {
  if (i.second == leastFavFreq)
  {
   greatestLeastFav = max(greatestLeastFav, i.first);
  }
 }
 return greatestLeastFav;
}