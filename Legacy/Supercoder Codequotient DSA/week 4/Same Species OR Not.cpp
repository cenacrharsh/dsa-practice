#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// Return true if the creatures belong to the same species, else return false
bool belongToSameSpecies(string DNA_str1, string DNA_str2)
{
 // Write your code here
 int i = 0;
 int j = 0;
 int n = DNA_str1.size();
 int m = DNA_str2.size();
 while (i < n && j < m)
 {
  if (DNA_str1[i] == DNA_str2[j])
  {
   j++;
  }
  i++;
 }
 if (j == m)
 {
  return true;
 }
 else
 {
  return false;
 }
}