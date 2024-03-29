/*
Average Flex Problem Code: AVGFLEX

Read problem statements in Mandarin, Bengali, and Russian as well.
There are N students in a class, where the i-th student has a score of Ai.

The i-th student will boast if and only if the number of students scoring less than or equal Ai is greater than the number of students scoring greater than Ai.

Find the number of students who will boast.

Input Format
The first line contains T - the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N - the number of students.
The second line of each test case contains N integers A1,A2,…,AN - the scores of the students.
Output Format
For each test case, output in a single line the number of students who will boast.

Constraints
1≤T≤1000
1≤N≤100
0≤Ai≤100
Sample Input 1 
3
3
100 100 100
3
2 1 3
4
30 1 30 30
Sample Output 1 
3
2
3
Explanation
Test case 1: All three students got the highest score. So all three of them will boast.
Test case 2: Only the student with score 1 will not be able to boast.
Test case 3: Only the student with score 1 will not be able to boast.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  int marks[n];
  for (int i = 0; i < n; i++)
  {
   cin >> marks[i];
  }
  int ans = 0;
  int less_eq = 0;
  for (int i = 0; i < n; i++)
  {
   int current = marks[i];
   for (int j = 0; j < n; j++)
   {
    if (j != i && marks[j] <= current)
    {
     less_eq++;
    }
   }

   int more = n - less_eq - 1;
   bool boast;
   if (less_eq >= more)
   {
    ans++;
   }

   less_eq = 0;
  }

  cout << ans << endl;
 }
 return 0;
}