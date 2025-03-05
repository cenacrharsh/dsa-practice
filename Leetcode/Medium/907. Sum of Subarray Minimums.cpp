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
  vector<int> findNextSmallerElement(vector<int> &arr)
  {
    vector<int> nse(arr.size(), 0);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
      //* pop any element which is >= our curr element, as we are looking for smaller elements
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
        st.pop();
      }
      nse[i] = st.empty() ? arr.size() : st.top(); //* if stack is empty we'll pass index N
      st.push(i);
    }
    return nse;
  }

  vector<int> findPreviousSmallerOrEqualElement(vector<int> &arr)
  {
    vector<int> psee(arr.size(), 0);
    stack<int> st;
    for (int i = 0; i <= arr.size() - 1; i++)
    {
      //* pop any element which is > our curr element, as we are looking for smaller or eq elementsj
      while (!st.empty() && arr[st.top()] > arr[i])
      {
        st.pop();
      }
      psee[i] = st.empty() ? -1 : st.top(); //* if stack is empty we'll pass -1
      st.push(i);
    }
    return psee;
  }

  int sumSubarrayMins(vector<int> &arr)
  {
    //* Optimised approach is to calculate the contribution of each element as the smallest element in total number of subarrays
    //* For this we'll need next smallest element as until next smallest element is encountered our current element will be the smallest in the subarray hence contributing to our total answer. Similarly we also need previous smaller element but to avoid duplicate subarrays eg (1, 1) what we'll do is calc prev smaller or eq elementTT
    long long total = 0, mod = (int)(1e9 + 7);
    vector<int> nse = findNextSmallerElement(arr);
    vector<int> psee = findPreviousSmallerOrEqualElement(arr);

    for (int i = 0; i <= arr.size() - 1; i++)
    {
      int smallerElementsToTheLeft = i - psee[i];
      int smallerElementsToTheRight = nse[i] - i;

      total = (total + (smallerElementsToTheLeft * smallerElementsToTheRight * 1LL * arr[i]) % mod) % mod;
    }
    return total;
  }
};