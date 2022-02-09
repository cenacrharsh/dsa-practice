#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> xorQuery(vector<vector<int>> &queries)
{
 // Write your code here
 //     vector<int> ans;
 //     for(int i=0;i<queries.size();i++)
 //     {
 //         vector<int> query = queries[i];
 //         int query_type = query[0];
 //         int num = query[1];

 //         if(query_type == 1)
 //         {
 //             ans.push_back(num);
 //         }
 //         else if(query_type == 2)
 //         {
 //             for(int j=0;j<ans.size();j++)
 //             {
 //                 ans[j]=ans[j] ^ num;
 //             }
 //         }
 //     }
 //     return ans;
 vector<int> ans;
 vector<int> xor_arr(100001, 0);
 for (int i = 0; i < queries.size(); i++)
 {
  if (queries[i][0] == 1)
  {
   ans.push_back(queries[i][1]);
  }
  else
  {
   int n = ans.size();
   xor_arr[0] ^= queries[i][1];
   xor_arr[n] ^= queries[i][1];
  }
 }
 for (int i = 0; i < ans.size(); i++)
 {
  if (i == 0)
  {
   ans[0] = ans[0] ^ xor_arr[0];
  }
  else
  {
   xor_arr[i] = xor_arr[i] ^ xor_arr[i - 1];
   ans[i] = ans[i] ^ xor_arr[i];
   // since xor_arr had initial val of 0 so it contains all the xor queries but not with the original array elements hence another xor is required
  }
 }
 return ans;
}