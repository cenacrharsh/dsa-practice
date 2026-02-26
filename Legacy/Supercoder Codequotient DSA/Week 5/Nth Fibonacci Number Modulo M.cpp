#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int nthFibonacciTerm(int n, int m)
{
 // Complete the given function
 int fib[n + 1] = {0};
 fib[0] = 0;
 fib[1] = 1;
 for (int i = 2; i <= n; i++)
 {
  fib[i] = (fib[i - 1] % m + fib[i - 2] % m) % m;
 }
 return fib[n] % m;
}