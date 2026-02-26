#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int collectData(int height[], int n)
{
 // Write your code here
 stack<int> st;
 st.push(height[0]);
 int ans = 0;
 for (int i = 1; i < n; i++)
 {
  if (!st.empty() && height[i] > st.top())
  {
   while (!st.empty() && height[i] > st.top())
   {
    ans += height[i];
    st.pop();
   }
  }
  st.push(height[i]);
 }
 while (!st.empty())
 {
  ans += -1;
  st.pop();
 }
 return ans;
}