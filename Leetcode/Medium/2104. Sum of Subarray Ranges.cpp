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
> Time Complexity: O(5N) + O(5N)
> Space Complexity: O(5N) + O(5N)
*/

//* Sum of all Subarray Ranges => (Highest Element - Lowest Element) Of Each Subarray => Sum of Subarray Maximums - Sum of Subarray Minimums

vector<int> findNextLargerElement(vector<int> &arr)
{
  vector<int> nle(arr.size(), 0);
  stack<int> st;
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    //* pop any element which is <= our curr element, as we are looking for larger elements
    while (!st.empty() && arr[st.top()] <= arr[i])
    {
      st.pop();
    }
    nle[i] = st.empty() ? arr.size() : st.top(); //* if stack is empty we'll pass index N
    st.push(i);
  }
  return nle;
}

vector<int> findPreviousLargerOrEqualElement(vector<int> &arr)
{
  vector<int> plee(arr.size(), 0);
  stack<int> st;
  for (int i = 0; i <= arr.size() - 1; i++)
  {
    //* pop any element which is < our curr element, as we are looking for larger or eq elements
    while (!st.empty() && arr[st.top()] < arr[i])
    {
      st.pop();
    }
    plee[i] = st.empty() ? -1 : st.top(); //* if stack is empty we'll pass -1
    st.push(i);
  }
  return plee;
}

long long sumSubarrayMaxs(vector<int> &arr)
{
  long long total = 0;
  vector<int> nle = findNextLargerElement(arr);
  vector<int> plee = findPreviousLargerOrEqualElement(arr);

  for (int i = 0; i <= arr.size() - 1; i++)
  {
    int largerElementsToTheLeft = i - plee[i];
    int largerElementsToTheRight = nle[i] - i;

    total = total + (largerElementsToTheLeft * largerElementsToTheRight * 1LL * arr[i]);
  }
  return total;
}

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

long long sumSubarrayMins(vector<int> &arr)
{
  long long total = 0;
  vector<int> nse = findNextSmallerElement(arr);
  vector<int> psee = findPreviousSmallerOrEqualElement(arr);

  for (int i = 0; i <= arr.size() - 1; i++)
  {
    int smallerElementsToTheLeft = i - psee[i];
    int smallerElementsToTheRight = nse[i] - i;

    total = total + (smallerElementsToTheLeft * smallerElementsToTheRight * 1LL * arr[i]);
  }
  return total;
}

class Solution
{
public:
  long long subArrayRanges(vector<int> &nums)
  {
    return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
  }
};