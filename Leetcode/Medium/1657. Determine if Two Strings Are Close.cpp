#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

bool closeStrings(string word1, string word2)
{
 if (word1.size() != word2.size())
 {
  return false;
 }
 unordered_map<char, int> freq1, freq2;
 for (int i = 0; i < word1.size(); i++)
 {
  freq1[word1[i] - 'a']++;
 }
 for (int i = 0; i < word2.size(); i++)
 {
  freq2[word2[i] - 'a']++;
 }
 if (freq1.size() != freq2.size())
 {
  return false;
 }
 vector<int> v1, v2;
 vector<char> v3, v4;
 for (auto i : freq1)
 {
  v1.push_back(i.first);
  v3.push_back(i.second);
 }
 for (auto i : freq2)
 {
  v2.push_back(i.first);
  v4.push_back(i.second);
 }
 sort(v1.begin(), v1.end());
 sort(v2.begin(), v2.end());
 sort(v3.begin(), v3.end());
 sort(v4.begin(), v4.end());
 if (v1 == v2 && v3 == v4)
 {
  return true;
 }
 return false;
}