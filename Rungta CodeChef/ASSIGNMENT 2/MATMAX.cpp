/*
Maximum Difference Problem Code: MATMAX

Given a matrix of size N * M where N represent number of rows and M represents number of columns.

For a row we define a value called DiffValue which is difference between its largest term and the smallest term i.e (maximum term - minimum term). You have to answer the largest DiffValue among all the rows for the given matrix.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
First line of each test case contains two space separated integers N and M
Next N lines contain M space separated integers each denoting a row of the given matrix.
Output
For each test case, output a single line containing the maximum difference value of the given matrix.

Constraints
1 ≤ T ≤ 25
1 ≤ N,M ≤ 500
1 ≤ Value ≤ 10000  
Example
Input:
1
2 3
5 1 3
2 10 6

Output:
8 
Explanation
Difference value for row 1 is 4. Difference value for row 2 is 8. Hence, Maximum difference value over both the rows is 8.
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n, m;
  cin >> n >> m;

  int mat[n][m];
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < m; j++)
   {
    cin >> mat[i][j];
   }
  }

  int diffVal = 0;
  int max_diffVal = 0;
  for (int i = 0; i < n; i++)
  {
   int max_ele = mat[i][0];
   int min_ele = mat[i][0];
   for (int j = 0; j < m; j++)
   {
    max_ele = max(max_ele, mat[i][j]);
    min_ele = min(min_ele, mat[i][j]);
   }
   diffVal = max_ele - min_ele;
   max_diffVal = max(diffVal, max_diffVal);
  }

  cout << max_diffVal << endl;
 }
 return 0;
}