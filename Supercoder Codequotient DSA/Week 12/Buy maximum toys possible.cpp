#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//> for loop
int maxToys(int cost[], int n, int X)
{
 // Write your code here
 int remainingAmount = X;
 int count = 0;
 sort(cost, cost + n);
 for (int i = 0; i < n; i++)
 {
  if (remainingAmount < cost[i])
  {
   break;
  }

  remainingAmount -= cost[i];
  count++;
 }
 return count;
}

//> while loop
int maxToys(int cost[], int n, int X)
{
 // Write your code here
 sort(cost, cost + n);
 int count = 0;
 while (X >= 0 && count <= n)
 {
  X -= cost[count++];
 }
 // since 1 extra added when X goes below 0, we have to remove that product
 return count - 1;
}