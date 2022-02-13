#include <iostream>
using namespace std;

//! Approach 1

/*
> Time Complexity: O(1)
> Space Complexity: O(1)
*/

/*
* Sum of terms of AP: Sn = n/2 * (2*a + (n - 1) * d),
* where K * N <= X, hence N <= X / K
* a = first term of series
*/

long multipleSum(int x)
{
 long n;
 n = x / 3;
 long sum3 = (n * (2 * 3 + (n - 1) * 3)) / 2;
 n = x / 5;
 long sum5 = (n * (2 * 5 + (n - 1) * 5)) / 2;
 n = x / 15;
 long sum15 = (n * (2 * 15 + (n - 1) * 15)) / 2;

 return sum3 + sum5 - sum15;
}

//! Approach 2

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

long multipleSum(int x)
{
 long sum3 = 0, sum5 = 0, sum15 = 0;

 //> common multiples of (a, b) == multipes of lcm(a, b)

 for (int i = 3; i <= x; i += 3)
  sum3 += i;
 for (int i = 5; i <= x; i += 5)
  sum5 += i;
 for (int i = 15; i <= x; i += 15)
  sum15 += i;

 return sum3 + sum5 - sum15;
}

/*
long long int multipleSum(int x)
{
 // Write your code here
 long long ans = 0;
 long long multiples_of_3_5[x + 1] = {0};
 for (long long i = 1; i <= x; i++)
 {
  if (3 * i <= x)
  {
   multiples_of_3_5[3 * i] = 1;
  }
  if (5 * i <= x)
  {
   multiples_of_3_5[5 * i] = 1;
  }
 }
 for (long long i = 1; i <= x; i++)
 {
  if (multiples_of_3_5[i] == 1)
  {
   ans += i;
  }
 }
 return ans;
}
*/

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int x;
  cin >> x;
  cout << multipleSum(x) << "\n";
 }
 return 0;
}