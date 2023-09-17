#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int keywordCount(string str, string word)
{
 // Write your code here
 int n = str.length();
 int m = word.length();
 int count = 0;

 for (int i = 0; i < n; i++)
 {
  bool mismatch = false;
  for (int j = 0; j < m; j++)
  {
   if (str[i] == word[j])
   {
    i++;
   }
   else
   {
    mismatch = true;
    break;
   }
  }
  if (mismatch == false && (str[i] == ' ' || i == n))
  {
   count++;
  }
  else
  {
   while (i < n && str[i] != ' ')
   {
    i++;
   }
  }
 }
 return count;
}