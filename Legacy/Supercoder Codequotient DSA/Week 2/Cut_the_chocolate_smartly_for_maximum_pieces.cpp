#include <bits/stdc++.h>
using namespace std;

long maxPieces(int k)
{
 // Write your code here
 long vertical_cuts;
 if (k % 2 == 0)
 {
  vertical_cuts = k / 2;
 }
 else
 {
  vertical_cuts = (k / 2) + 1;
 }
 long horizontal_cuts = k - vertical_cuts;
 long ans = vertical_cuts * horizontal_cuts;
 return ans;
}

int main()
{
 int t;
 cin >> t;

 while (t--)
 {
  int k;
  cin >> k;
  cout << maxPieces(k) << endl;
 }

 return 0;
}