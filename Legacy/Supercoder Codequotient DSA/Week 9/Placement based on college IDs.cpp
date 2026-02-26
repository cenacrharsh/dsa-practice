#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int maxStudents(int collegeIDs[], int n)
{
 // Write your code here
 set<int> id;
 for (int i = 0; i < n; i++)
 {
  id.insert(collegeIDs[i]);
 }
 int maxConsecutive = 0;
 stack<int> st;
 for (int n : id)
 {
  if (st.empty() || st.top() + 1 == n)
  {
   st.push(n);
  }
  else
  {
   while (!st.empty())
   {
    st.pop();
   }
   st.push(n);
  }
  int count = st.size();
  maxConsecutive = max(maxConsecutive, count);
 }
 return maxConsecutive;
}