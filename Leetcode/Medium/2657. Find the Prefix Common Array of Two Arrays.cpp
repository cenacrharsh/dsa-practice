#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    unordered_map<int, int> temp;
    vector<int> ans(A.size(), 0);
    for (int i = 0; i < A.size(); i++)
    {
      int count = 0;
      for (int j = i; j >= 0; j--)
      {
        temp[B[j]]++;
        if (temp.find(A[j]) != temp.end())
        {
          count++;
        }
      }
      ans[i] = count;
    }
    return ans;
  }
};