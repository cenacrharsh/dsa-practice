#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N) + O(N) => Traversal + Pop from stack (max N as at max we push every element only once)
> Space Complexity: O(N)
*/

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    //* area = length * breadth = arr[i] * (nse - pse - 1)
    //* now if we don't want to iterate 2 times to calc nse and pse and do it in one go, we'll maintain a stack and start traversing from left to right, if we encounter bigger elements we'll keep pushing into stack, as soon as we encounter a smaller element we know we have found the nse to all the elements currently in the stack also since we are moving from left to right we already have a track of pse so basically we are calc. values as we go back from right to left and we keep kicking out elements until we reach the pse of our current element

    stack<int> st;
    int area = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
      // pop till top element of stack is greater than current element
      while (!st.empty() && heights[st.top()] > heights[i])
      {
        int topIndex = st.top();
        st.pop();
        int nse = i;
        int pse = st.empty() ? -1 : st.top();
        area = max(area, (heights[topIndex] * (nse - pse - 1)));
      }
      st.push(i);
    }

    // if stack is not empty then we have elements for which there is no nse so we consider it to be n
    while (!st.empty())
    {
      int topIndex = st.top();
      st.pop();
      int nse = heights.size();
      int pse = st.empty() ? -1 : st.top();
      area = max(area, (heights[topIndex] * (nse - pse - 1)));
    }
    return area;
  }
};