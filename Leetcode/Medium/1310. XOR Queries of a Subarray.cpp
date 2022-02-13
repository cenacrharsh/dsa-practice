#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
 vector<int> xorQueries(vector<int> &A, vector<vector<int>> &queries)
 {
  //         vector<int> ans;
  //         for(int i=0;i<queries.size();i++)
  //         {
  //             int l = queries[i][0];
  //             int r = queries[i][1];

  //             if(l == r)
  //             {
  //                 ans.push_back(arr[l]);
  //             }
  //             else
  //             {
  //             int temp = arr[l]^arr[r];
  //             for(int j=l+1;j<r;j++)
  //             {
  //                 temp = temp ^ arr[j];
  //             }
  //             ans.push_back(temp);
  //             }
  //         }
  //         return ans;
  vector<int> res;
  //         creating xor sum array
  for (int i = 1; i < A.size(); ++i)
   A[i] ^= A[i - 1];
  //         if we need from index 0 -> n then A[n] in xor sum array is our ans, but if initial index is not 0 eg. 2->4 then xor sum till index 1 should be romoved which we achieve by A[n]-A[starting index - 1]
  for (auto &q : queries)
   res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);
  return res;
 }
};