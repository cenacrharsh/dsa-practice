#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*

    Time Complexity - O(N)
    Space Complexity - O(N)

    Where 'N' is the number of elements in the array/list.

*/

void printNextGreaterElement(int arr[], int n)
{
 // Write your code here
 stack<int> st;
 vector<int> ans(n);

 // Stack, to keep track of next greater element.
 stack<int> s;

 // Traverse in reverse fashion in the array.
 for (int i = n - 1; i >= 0; i--)
 {

  /*
      If current element is greater than stack's top
      element, we can pop it since now it will never get
      picked as the next greater, because current element
      is greater and appear earlier.
  */
  while (!s.empty() && arr[i] >= s.top())
  {
   s.pop();
  }

  /*
      If stack is not empty, stack's top element is
      the next greater element, else there is none.
  */
  if (!s.empty())
  {
   ans[i] = s.top();
  }
  else
  {
   ans[i] = -1;
  }

  // Push current element onto stack.
  s.push(arr[i]);
 }

 for (auto i : ans)
 {
  cout << i << " ";
 }
}

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
