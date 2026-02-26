//# Tutorial: https://www.youtube.com/watch?v=BvKv-118twg
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

/*
! if we want sum of 2 elements to be divisible by K, then one should be of type Kn + x and the other Km + (K-x), so that they add up to become K(n+m) + K which will be divisible by K.

! if our case where div by k and remainder m is required our reamainders should be x and m - x, then rest is as above

> for elements like 0 remainder wale, and K/2 remainder types -> they should have even frequency

* so we'll store all the freq in our hashmap and check
*/

/*
> (a + b) % K = (a % K + b % K) % K.
*/

//! Approach 1 - Hashmap

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

bool isValidPair(vector<int> &arr, int n, int k, int m)
{

 //* An odd length array cannot be divided into pairs.
 if (n % 2 == 1)
 {
  return false;
 }

 //* Create a frequency array to count occurrences of all remainders when divided by k.
 unordered_map<int, int> map;

 for (int i = 0; i < n; i++)
 {
  int rem = arr[i] % k;
  map[rem]++;
 }

 unordered_map<int, int>::iterator itr;

 for (itr = map.begin(); itr != map.end(); itr++)
 {
  int rem = itr->first;

  //* If current remainder divides m into two halves.
  if (2 * rem == m)
  {
   //* Then there must be even occurrences of such remainder.
   if (map[rem] % 2 == 1)
   {
    return false;
   }
  }

  //* Else number of occurrences of remainder must be equal to number of occurrences of m - remainder.
  else
  {
   if (map[(m - rem + k) % k] != map[rem])
   {
    return false;
   }
  }
 }

 return true;
}

//! Approach 2

/*
> Time Complexity: O(n2)
> Space Complexity: O(n)
*/

bool isValidPair(vector<int> &arr, int n, int k, int m)
{

 // An odd length array cannot be divided into pairs.
 if (n % 2 == 1)
 {
  return false;
 }

 bool visited[n];

 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {

   // If arr[i] and arr[j] is not included in any pair.
   if (visited[i] == false && visited[j] == false)
   {
    if ((arr[i] + arr[j]) % k == m)
    {
     visited[i] = true;
     visited[j] = true;

     /*
If any pair formed, then break and
move to next pair that can be formed.
*/
     break;
    }
   }
  }
 }

 // Check the condition if all the elements can be paired.
 for (int i = 0; i < n; i++)
 {
  if (visited[i] == false)
  {
   return false;
  }
 }

 return true;
}
