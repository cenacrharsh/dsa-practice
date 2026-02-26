#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int getMissingElement(vector<int> A, vector<int> B)
{
 // Write your code here
 int sum = 0;
 for (int i : A)
 {
  sum ^= i;
 }
 for (int i : B)
 {
  sum ^= i;
 }
 return sum;
}