#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_map>
int smallestSubstringPossible(string s, string t)
{
 // Write your code here
 int n = s.size();
 int m = t.size();

 string ans = "";

 unordered_map<char, int> map2;
 for (int i = 0; i < m; i++)
 {
  map2[t[i]]++;
 }

 int match_count = 0;
 int desired_match_count = t.size();
 unordered_map<char, int> map1;
 int i = -1, j = -1;

 while (true)
 {
  bool f1 = false, f2 = false;

  // acquire, i < n - 1 since we are doing i++ before all calc
  while ((i < n - 1) && (match_count < desired_match_count))
  {
   i++;
   char acquired_character = s.at(i);
   map1[acquired_character]++;

   if (map1[acquired_character] <= map2[acquired_character])
   {
    match_count++;
   }

   f1 = true;
  }

  // collect answers and release
  while ((j < i) && (match_count == desired_match_count))
  {
   j++;

   string potential_ans = s.substr(j, i - j + 1);

   if (ans.size() == 0 || potential_ans.size() < ans.size())
   {
    ans = potential_ans;
   }

   char removed_character = s.at(j);
   if (map1[removed_character] == 1)
   {
    map1.erase(removed_character);
   }
   else
   {
    map1[removed_character]--;
   }

   if (map1[removed_character] < map2[removed_character])
   {
    match_count--;
   }

   f2 = true;
  }

  if (f1 == false && f2 == false)
  {
   break;
  }
 }

 if (ans.size() == 0)
 {
  return -1;
 }

 return ans.size();
}