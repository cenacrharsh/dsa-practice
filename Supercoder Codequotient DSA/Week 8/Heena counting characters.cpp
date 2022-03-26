#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

void countFrequency(string str)
{
 // write your code here
 map<char, int> freq;
 for (int i = 0; i < str.size(); i++)
 {
  freq[str[i]]++;
 }
 for (auto i : freq)
 {
  cout << i.first << i.second << " ";
 }
}
