#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
 * Complete the 'findAverage' function below.
 * @params
 * n -> integer denoting the number of cities from 1 to n
 * m -> integer denoting the number of phases
 * arr -> 2-D vector with 'm' rows, where arr[i][0] denotes 'a',
 *        arr[i][1] denotes 'b' and arr[i][2] denotes 'k' for the ith phase
 *
 * @return
 * An integer denoting the average number of people settled per city.
 */

/*
 * Complete the 'findAverage' function below.
 * @params
 * n -> integer denoting the number of cities from 1 to n
 * m -> integer denoting the number of phases
 * arr -> 2-D vector with 'm' rows, where arr[i][0] denotes 'a',
 *        arr[i][1] denotes 'b' and arr[i][2] denotes 'k' for the ith phase
 *
 * @return
 * An integer denoting the average number of people settled per city.
 */

//! calulation only the population sum

int findAverage(int n, int m, vector<vector<int>> &arr)
{
 // Write your code here
 long long int population = 0;
 for (int i = 0; i < m; i++)
 {
  int a = arr[i][0];
  int b = arr[i][1];
  int k = arr[i][2];

  population = population + (b - a + 1) * k;
 }
 return population / n;
}

//! Doing it in one pass

int findAverage(int n, int m, vector<vector<int>> &arr)
{
 // Write your code here
 vector<int> population(n + 1, 0);
 for (int i = 0; i < m; i++)
 {
  int a = arr[i][0];
  int b = arr[i][1];
  int k = arr[i][2];

  // cout << "a: " << a << " b: " << b << " k: " << k << endl;

  population[a] += k;
  if (b + 1 <= n)
  {
   population[b + 1] -= k;
  }
 }
 long long int sum = population[0];
 for (int i = 1; i <= n; i++)
 {
  population[i] += population[i - 1];
  sum += population[i];
 }
 // for (int i = 1; i <= n; i++)
 // {
 //  cout << population[i] << " ";
 // }
 // cout << endl;
 // cout << "sum: " << sum << endl;
 return sum / n;
}

int main()
{
 int n, m;
 cin >> n >> m;
 vector<vector<int>> arr;
 for (int i = 0; i < m; i++)
 {
  vector<int> vec(3);
  cin >> vec[0] >> vec[1] >> vec[2];
  arr.push_back(vec);
 }
 cout << findAverage(n, m, arr);

 return 0;
}