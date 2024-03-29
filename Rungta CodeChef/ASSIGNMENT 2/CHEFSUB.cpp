/*
Longest Subarray Problem Code: CHEFSUB

You are given an array A of N integers: A1, A2, ..., AN. You need to find a longest contiguous subarray in the array such that each integer in this subarray is an even integer, and output its length.

A contiguous subarray is of the form Ai, Ai+1, ..., Aj, for some i and j.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of each test case follows.
The first line of each test case contains a single integer N denoting the number of elements in the given array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the array A.
Output
For each test case, output a single line containing the answer.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ A1, A2, ... , AN ≤ 105
Information to score partial points
For 16% of the score, it is guaranteed that N ≤ 100.
For further 16% of the score, it is guaranteed that N ≤ 1000.
For the rest of the 68% of the score, no extra guarantees. That is, N ≤ 105.
Example
Input:
3
4
1 2 2 4
3
2 4 6
5
2 3 2 2 5

Output:
3
3
2
Explanation
Testcase 1: The longest contiguous subarray that has all its elements even will be the subarray consisting of the 3 elements [2, 2, 4]. Hence, the answer will be 3.

Testcase 2: The longest contiguous subarray that has all its elements even will be the subarray consisting of the 3 elements [2, 4, 6]. Hence, the answer will be 3.

Testcase 3: The longest contiguous subarray that has all its elements even will be the subarray consisting of the 2 elements [2, 2]. Hence, the answer will be 2.
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
 long long int t;
 cin >> t;
 while (t--)
 {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++)
  {
   cin >> arr[i];
  }

  long long int curr_count = 0;
  long long int max_count = 0;
  for (int i = 0; i < n; i++)
  {
   if (arr[i] % 2 == 0)
   {
    curr_count++;
    max_count = max(curr_count, max_count);
   }
   else if (arr[i] % 2 == 1)
   {
    curr_count = 0;
   }
  }
  cout << max_count << endl;
 }
 return 0;
}