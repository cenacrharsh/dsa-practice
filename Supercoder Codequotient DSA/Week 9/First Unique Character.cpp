#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_map>
int firstUniqueChar(string str)
{
 // Write your code here
 unordered_map<char, int> freq;
 for (int i = 0; i < str.size(); i++)
 {
  freq[str[i]]++;
 }
 for (int i = 0; i < str.size(); i++)
 {
  if (freq[str[i]] == 1)
  {
   return i;
  }
 }
 return -1;
}