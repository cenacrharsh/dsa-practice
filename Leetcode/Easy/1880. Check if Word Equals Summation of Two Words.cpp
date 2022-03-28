#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using to_string() and stoi()

class Solution
{
public:
 bool isSumEqual(string firstWord, string secondWord, string targetWord)
 {
  string s1 = "", s2 = "", s3 = "";
  for (char ch : firstWord)
  {
   s1 += to_string(ch - 'a');
  }
  for (char ch : secondWord)
  {
   s2 += to_string(ch - 'a');
  }
  for (char ch : targetWord)
  {
   s3 += to_string(ch - 'a');
  }
  int sum = stoi(s1) + stoi(s2);
  int target = stoi(s3);
  return (sum == target);
 }
};