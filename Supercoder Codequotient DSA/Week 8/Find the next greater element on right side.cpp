#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

void printNextGreaterElement(int arr[], int n)
{
 // Write your code here
 unordered_map<int, int> map;
 stack<int> st;
 st.push(arr[0]);
 for (int i = 1; i < n; i++)
 {
  if (!st.empty() && arr[i] > st.top())
  {
   while (!st.empty() && arr[i] > st.top())
   {
    map[st.top()] = arr[i];
    st.pop();
   }
  }
  st.push(arr[i]);
 }
 while (!st.empty())
 {
  map[st.top()] = -1;
  st.pop();
 }
 for (int i = 0; i < n; i++)
 {
  cout << map[arr[i]] << " ";
 }
}
