#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Approach 1

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

#include <unordered_map>

vector<int> majorityElementII(vector<int> &arr)
{
 int n = arr.size();

 //* Array for storing final answer.
 vector<int> majorityElement;

 //* HashMap to store the frequency of every element.
 unordered_map<int, int> freq;

 //* Iterate through the array/list.
 for (int i = 0; i < n; i++)
 {
  //* Increment the value in the HashMap.
  freq[arr[i]] = freq[arr[i]] + 1;
 }

 //* Iterate through the HashMap
 for (auto i : freq)
 {
  //* Store all the elements with frequency greater than n/3.
  if (i.second > n / 3)
  {
   majorityElement.push_back(i.first);
  }
 }

 //* Return all the stored majority elements.
 return majorityElement;
}

//! Approach 2

/*
> Time Complexity: O(n*logn)
> Space Complexity: O(1)
*/

vector<int> majorityElementII(vector<int> &arr)
{
 // Write your code here.
 vector<int> ans;
 int n = arr.size();
 sort(arr.begin(), arr.end());
 int reqCount = floor(float(n / 30));
 int ans = -1;
 int i = 0;
 int startVertex = 0;

 while (i < n)
 {
  while (arr[i] == arr[i + 1])
  {
   i++;
  }
  int tempCount = i - startVertex + 1;
  if (tempCount > reqCount)
  {
   ans.push_back(arr[i]);
  }
  startVertex = i + 1;
  i++;
 }
 return ans;
}