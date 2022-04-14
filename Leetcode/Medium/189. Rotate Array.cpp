#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 void rotate(vector<int> &nums, int k)
 {
  k = k % nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
 }
};