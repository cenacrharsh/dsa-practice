#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
 unordered_map<int, int> freq;
 int count = 0;

 for (int i = 0; i < n; i++)
 {
  //! now we update/add arr[i] in the freq array
  if (freq.find(arr[i]) != freq.end())
  {
   freq[arr[i]]++;
  }
  else
  {
   freq[arr[i]] = 1;
  }
 }

 for (auto ele : freq)
 {
  int second_element = ele.first + k;

  if (freq.find(second_element) != freq.end())
  {
   count += freq[second_element];
  }
 }

 return count;
}

int main()
{
 int T, n, k;
 cin >> T;
 while (T--)
 {
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
   cin >> arr[i];
  cout << getPairsCount(arr, n, k) << endl;
 }
 return 0;
}