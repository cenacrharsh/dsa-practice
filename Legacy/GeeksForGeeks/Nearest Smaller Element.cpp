#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &A)
{
  int n = A.size();
  vector<int> ans(n, 0);
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && st.top() >= A[i])
    {
      st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(A[i]);
  }
  return ans;
}
