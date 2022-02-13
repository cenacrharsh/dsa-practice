#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class NumArray
{
private:
 vector<int> accu;

public:
 NumArray(vector<int> &nums)
 {
  accu.push_back(0);
  for (int num : nums)
   accu.push_back(accu.back() + num);
 }

 int sumRange(int i, int j)
 {
  return accu[j + 1] - accu[i + 1 - 1];
  //         +1 since it's 1 based indexing
 }
};

/*
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */