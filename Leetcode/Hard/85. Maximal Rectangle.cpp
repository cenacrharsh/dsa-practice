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
> Time Complexity: O(M * N) + O(N * 2M) => Pref Sum + (Loop over rows * Histogram Area per row)
> Space Complexity: O(N * M) + O(N) => Pref Sum + Stack
*/

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
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

  int maximalRectangle(vector<vector<char>> &matrix)
  {
    //* we'll use the concept of maximum area of histogram, we'll iterate one row at a time and calculate all rectangles formed, also to know which blocks have 1 we use a prefixSum col wise to know at any level what lies above it

    int row = matrix.size(), col = matrix[0].size();
    int maxArea = INT_MIN;
    vector<vector<int>> prefSum(row, vector<int>(col, 0));

    for (int j = 0; j < col; j++)
    {
      int sum = 0;
      for (int i = 0; i < row; i++)
      {
        int val = matrix[i][j] - '0';
        sum += val;
        if (val == 0)
        {
          sum = 0;
        }
        prefSum[i][j] = sum;
      }
    }

    for (int i = 0; i < row; i++)
    {
      maxArea = max(maxArea, largestRectangleArea(prefSum[i]));
    }

    return maxArea;
  }
};