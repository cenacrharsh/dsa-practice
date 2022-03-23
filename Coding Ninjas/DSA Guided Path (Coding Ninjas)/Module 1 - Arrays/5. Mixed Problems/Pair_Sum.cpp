#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! using hashmap

/*
> Time Complexity: O(n2)
> Space Complexity: O(n)
*/

#include <map>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
 int n = arr.size();

 // Map to store frequency of elements.
 map<int, int> hash;

 // This will store the result.
 vector<vector<int>> ans;

 for (int ele : arr)
 {
  int count = hash[s - ele];

  vector<int> pair(2);
  pair[0] = ele;
  pair[1] = s - ele;

  while (count--)
  {
   ans.push_back(pair);
  }

  hash[ele] += 1;
 }

 // This will store the final result.
 vector<vector<int>> res(ans.size(), vector<int>(2, 0));

 // Sorting the 'ans' arrays element.
 for (int i = 0; i < ans.size(); i++)
 {
  int a = ans[i][0], b = ans[i][1];
  res[i][0] = min(a, b);
  res[i][1] = max(a, b);
 }

 // Finally sorting each pair in 'res'.
 sort(res.begin(), res.end());
 return res;
}

//! 2 poiners

/*
> Time Complexity: O(n2)
> Space Complexity: O(n)
*/

#include <map>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
 // Used to store result.
 vector<vector<int>> ans;

 map<int, int> mp;
 vector<int> keyArray;
 for (int num : arr)
 {

  if (!mp.count(num))
  {
   keyArray.push_back(num);
  }

  // Store frequency of each unique element.
  mp[num] += 1;
 }

 sort(keyArray.begin(), keyArray.end());

 for (int key : keyArray)
 {

  if (key + key == s)
  {

   int freq = mp[key];

   // Total number of such pairs will be 'FREQ*(FREQ-1)/2'.
   for (int j = 0; j < freq * (freq - 1) / 2; j++)
   {

    ans.push_back({key, key});
   }
  }
 }

 // Maintain two pointers.
 int low = 0;
 int high = keyArray.size() - 1;

 while (low < high)
 {

  int currSum = keyArray[low] + keyArray[high];

  // If the current sum is equal to the target sum.
  if (currSum == s)
  {

   int freq = mp[keyArray[low]] * mp[keyArray[high]];

   // Total number of such pairs will be 'FREQ'.
   for (int j = 0; j < freq; j++)
   {

    ans.push_back({keyArray[low], keyArray[high]});
   }

   low++;
   high--;
  }
  else if (currSum < s)
  {

   low++;
  }
  else
  {

   high--;
  }
 }

 for (int i = 0; i < ans.size(); i++)
 {

  int a = ans[i][0], b = ans[i][1];
  ans[i][0] = min(a, b);
  ans[i][1] = max(a, b);
 }

 sort(ans.begin(), ans.end());
 return ans;
}

//! Brute Force

/*
> Time Complexity: O(n2)
> Space Complexity: O(1)
*/

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
 // Write your code here.
 sort(arr.begin(), arr.end());
 vector<vector<int>> validPairs;
 for (int i = 0; i < arr.size(); i++)
 {
  for (int j = i + 1; j < arr.size(); j++)
  {
   vector<int> tempPair;
   if (arr[i] + arr[j] == s)
   {
    tempPair.push_back(arr[i]);
    tempPair.push_back(arr[j]);
    validPairs.push_back(tempPair);
   }
  }
 }
 return validPairs;
}