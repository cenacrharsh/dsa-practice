/*
A Subtask Problem Problem Code: SUBTASK

Submit
Chef recently solved his first problem on CodeChef. The problem he solved has N test cases. He gets a score for his submission according to the following rules:

1) If Chef’s code passes all the N test cases, he gets 100 points.

2) If Chef’s code does not pass all the test cases, but passes all the first M(M<N) test cases, he gets K(K<100) points.

3) If the conditions 1 and 2 are not satisfied, Chef does not get any points (i.e his score remains at 0 points).

You are given a binary array A1,A2,…,AN of length N, where Ai=1 denotes Chef's code passed the ith test case, Ai=0 denotes otherwise. You are also given the two integers M,K. Can you find how many points does Chef get?

Input Format
First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contains three space-separated integers N,M,K.
The second line contains N space-separated integer A1,A2,…,AN.
Output Format
For each testcase, output in a single line the score of Chef.

Constraints
1≤T≤100
2≤N≤100
1≤M<N
1≤K<100
0≤Ai≤1
Sample Input 1 
4
4 2 50
1 0 1 1
3 2 50
1 1 0
4 2 50
1 1 1 1
5 3 30
1 1 0 1 1
Sample Output 1 
0
50
100
0
Explanation
Test case 1: Chef's code neither passes all 4 test cases nor passes the first 2 test cases. Hence he does not get any points.

Test case 2: Chef's code does not pass all 3 test cases, but passes the first 2 test cases. Hence he gets 50 points.

Test case 3: Chef's code passes all the 4 test cases. Hence he gets 100 points.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n, m, k;
  cin >> n >> m >> k;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
   cin >> arr[i];
  }

  int pts = 0;
  bool subtask = true;
  bool alltask = true;
  for (int i = 0; i < n; i++)
  {
   if (arr[i] == 0 && i < m)
   {
    subtask = false;
   }

   if (arr[i] == 0)
   {
    alltask = false;
   }
  }

  if (alltask)
  {
   pts = 100;
  }
  else if (subtask)
  {
   pts = k;
  }

  cout << pts << endl;
 }
 return 0;
}