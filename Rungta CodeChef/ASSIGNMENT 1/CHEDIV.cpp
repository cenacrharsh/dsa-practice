/*
Simple Division Problem Code: CHEDIV
Given an array A of N integers and two integers X and Y, find the number of integers in the array that are both less than or equal to X and divisible by Y.
Input
The first line of the input contains an integer T denoting the number of test cases. The description of each test case follows.
The first line of each test case contains three space separated integers: N, X and Y.
The second line contains N space-separated integers A1, A2, ..., AN denoting the array A.
Output
For each test case, output a single line containing the answer.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ A1, A2, ... ,AN ≤ 109
1 ≤ X, Y ≤ 109
Information to score partial points
For 20% of the score, it is guaranteed that N ≤ 100.
For further 30% of the score, it is guaranteed that N ≤ 1000.
For the rest of the 50% of the score, no extra guarantees. That is, N ≤ 105.
Example
Input 1:
1
3 2 1
1 2 3

Output 1:
2

Input 2:
2
5 10 3
4 6 12 3 9
1 10 10
20

Output 2:
3
0

Explanation
Example case 1: All integers of the array are divisible by Y = 1 but only A1 = 1 and A2 = 2 are less than or equal to X = 2. Hence, the count for the number of integers that are less than or equal to 2 and divisible by 1 is 2.

Example case 2:

Testcase 1: We want to count the number of integers which are less than or equal to X = 10 and divisible by Y = 3. The only integers in the array which fit both these criteria are A2 = 6, A4 = 3 and A5 = 9. Since there are three of them, the answer is 3.

Testcase 2: We want to count the number of integers which are less than or equal to X = 10 and divisible by Y = 10. No integer in the array fits both the criteria. Since there are no valid integers, the answer is 0.
*/

#include <iostream>
using namespace std;

int main()
{
 // your code goes here
 int t;
 cin >> t;
 while (t--)
 {
  int n, x, y;
  cin >> n >> x >> y;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
   cin >> arr[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
   if ((arr[i] <= x) && (arr[i] % y == 0))
   {
    count++;
   }
  }
  cout << count << endl;
 }
 return 0;
}
