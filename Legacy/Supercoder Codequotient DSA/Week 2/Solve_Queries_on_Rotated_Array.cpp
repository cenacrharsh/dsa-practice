#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Print the answer of each query, separated by space
void solveQueries(int N, int R, int arr[], int Q, int queries[])
{
 // Write your code here
 for (int i = 0; i < Q; i++)
 {
  int index_after_rotation = (queries[i] + R) % N;
  cout << arr[index_after_rotation] << " ";
 }
}