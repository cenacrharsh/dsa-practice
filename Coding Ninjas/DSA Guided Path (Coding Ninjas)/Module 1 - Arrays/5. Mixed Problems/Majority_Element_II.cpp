#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Approach 1

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

vector<int> majorityElementII(vector<int> &arr)
{
 int n = arr.size();

 // Array for storing final answer.
 vector<int> majorityElement;

 // Variables for storing the elements which may occur more than n/3 times.
 int firstCandidate = 0, secondCandidate = 0;

 // Variables for storing the frequency of the candidate elements.
 int firstCount = 0, secondCount = 0;

 // Iterate through the array.
 for (int i = 0; i < n; i++)
 {
  // Increment firstCount if the current element is equal to firstCandidate.
  if (arr[i] == firstCandidate)
  {
   firstCount = firstCount + 1;
  }

  // Increment secondCount if the current element is equal to secondCandidate.
  else if (arr[i] == secondCandidate)
  {
   secondCount = secondCount + 1;
  }
  // Change value of the firstCandidate to the current element if firstCount is equal to 0.
  else if (firstCount == 0)
  {
   firstCandidate = arr[i];
   firstCount = 1;
  }

  // Change value of the secondCandidate to the current element if secondCount is equal to 0.
  else if (secondCount == 0)
  {
   secondCandidate = arr[i];
   secondCount = 1;
  }

  // Otherwise decrement firstCount and secondCount by 1.
  else
  {
   firstCount = firstCount - 1;
   secondCount = secondCount - 1;
  }
 }

 firstCount = 0;
 secondCount = 0;

 // Iterate through the array to find frequency of firstCandidate and secondCandidate.
 for (int i = 0; i < n; i++)
 {
  // Increment firstCount if the current element is equal to firstCandidate.
  if (arr[i] == firstCandidate)
  {
   firstCount = firstCount + 1;
  }

  // Increment secondCount if the current element is equal to secondCandidate.
  else if (arr[i] == secondCandidate)
  {
   secondCount = secondCount + 1;
  }
 }

 // Include firstCandidate in the answer if its frequency is more than n/3.
 if (firstCount > n / 3)
 {
  majorityElement.push_back(firstCandidate);
 }

 // Include secondCandidate in the answer if its frequency is more than n/3.
 if (secondCount > n / 3)
 {
  majorityElement.push_back(secondCandidate);
 }

 // Return all stored majority elements.
 return majorityElement;
}

//! Approach 2 - hashmap

/*
> Time Complexity: O(n) / O(n*logn)
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

//! Approach 3

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