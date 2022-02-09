#include <iostream>
using namespace std;

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