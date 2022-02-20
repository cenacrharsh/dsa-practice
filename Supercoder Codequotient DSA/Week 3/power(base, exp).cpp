#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

long power(int base, int exp)
{
 if (exp < 0)
 {
  return -1;
 }
 if (exp == 0)
 {
  return 1;
 }
 if (exp == 1)
 {
  return base;
 }
 long prod = 1;
 prod = base * power(base, exp - 1);
 return prod;
}