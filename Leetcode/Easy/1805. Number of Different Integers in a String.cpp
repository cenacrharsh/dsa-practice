#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_set>
class Solution
{
public:
 int numDifferentIntegers(string word)
 {
  unordered_set<string> s;
  for (int i = 0; i < word.length(); i++)
  {
   if (word[i] >= '0' && word[i] <= '9')
   {
    string num = "";
    while (i < word.length() && word[i] >= '0' && word[i] <= '9')
    {
     num = num + word[i];
     i++;
    }

    int j = 0;
    while (j < num.length() && num[j] == '0')
    {
     j++;
    }
    num = num.substr(j);
    s.insert(num);
   }
  }
  return s.size();
 }
};