// #include <bits/stdc++.h>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <unordered_map>
// using namespace std;

// /*
// > Time Complexity: O(N x log(M x 10^d))
// > Space Complexity: O(1)
// */

// double multiply(double number, int n)
// {
//  double ans = 1.0;
//  for (int i = 1; i <= n; i++)
//  {
//   ans = ans * number;
//  }
//  return ans;
// }

// void getNthRoot(int n, int m)
// {
//  double low = 1;
//  double high = m;
//  double eps = 1e-7;

//  while ((high - low) > eps)
//  {
//   double mid = (low + high) / 2.0;
//   if (multiply(mid, n) < m)
//   {
//    low = mid;
//   }
//   else
//   {
//    high = mid;
//   }
//  }

//  cout << n << "th root of " << m << " is " << low << endl;
// }
// int main()
// {
//  int t;
//  cin >> t;
//  while (t--)
//  {
//   int n, m;
//   cin >> n >> m;
//   getNthRoot(n, m);
//  }
//  return 0;
// }
