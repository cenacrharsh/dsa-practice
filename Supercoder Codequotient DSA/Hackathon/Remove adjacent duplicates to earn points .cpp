#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O()
*/

/*
! Algo:

> 1. if the leftmost end of the string contains duplicate char, then remove them and recur for the remaining string

> 2. else, if the first 2 char are distinct, then ignore the first char and recur for the remaining string

> 3. let the string obtained after reducing the remaining string be rem_reduced_str

> 4. now we have the first char and rem_reduced_str

* a) if the first char of rem_reduced_str and the original string matches, then remove rem_reduced_str's first char

* b) else, if rem_reduced_str becomes empty and the last removed char in recursive calls is the same as first char of the original string. Ignore the first char of the original string and return rem_reduced_str

* c) else, append the first char of the original string at the beginning of rem_reduced_str
*/

string removeAdjDup(string str, char last_removed)
{
 // If length of string is 1 or 0
 if (str.length() == 0 || str.length() == 1)
  return str;

 // Remove leftmost same characters and recur for remaining string
 if (str[0] == str[1])
 {
  last_removed = str[0];
  while (str.length() > 1 && str[0] == str[1])
   str.erase(str.begin());
  str.erase(str.begin());
  return removeAdjDup(str, last_removed);
 }

 // Recursively remove adj duplicates in remaining string
 string rem_reduced_str = removeAdjDup(str.substr(1), last_removed);

 // a) If first character of rem_reduced_str matches with the first character of original string,
 //  remove the first character from rem_reduced_str.
 if (rem_reduced_str.length() > 0 && rem_reduced_str[0] == str[0])
 {
  last_removed = str[0];

  // Remove first character
  return rem_reduced_str.substr(1);
 }

 // b) If remaining string becomes empty and last removed character
 //  is the same as the first character of the original string.
 if (rem_reduced_str.length() == 0 && last_removed == str[0])
  return rem_reduced_str;

 // c) If the two first characters of s and rem_reduced_str don't match,
 //  append first character of s before the first character of
 //  rem_reduced_str.
 return (str[0] + rem_reduced_str);
}

int totalPoints(string str)
{
 char last_removed = '\0';
 string finalStr = removeAdjDup(str, last_removed);

 return (str.length() - finalStr.length()) * 2;
}