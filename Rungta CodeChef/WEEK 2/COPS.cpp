/*
Cops and the Thief Devu Problem Code: COPS

Read problems statements in Mandarin Chinese and Russian as well.
There are 100 houses located on a straight line. The first house is numbered 1 and the last one is numbered 100. Some M houses out of these 100 are occupied by cops.

Thief Devu has just stolen PeePee's bag and is looking for a house to hide in.

PeePee uses fast 4G Internet and sends the message to all the cops that a thief named Devu has just stolen her bag and ran into some house.

Devu knows that the cops run at a maximum speed of x houses per minute in a straight line and they will search for a maximum of y minutes. Devu wants to know how many houses are safe for him to escape from the cops. Help him in getting this information.

Input
First line contains T, the number of test cases to follow.

First line of each test case contains 3 space separated integers: M, x and y.

For each test case, the second line contains M space separated integers which represent the house numbers where the cops are residing.

Output
For each test case, output a single line containing the number of houses which are safe to hide from cops.

Constraints
1 ≤ T ≤ 104
1 ≤ x, y, M ≤ 10
Sample Input 1 
3
4 7 8
12 52 56 8
2 10 2
21 75
2 5 8
10 51
Sample Output 1 
0
18
9
Explanation
Example 1 : Cops in house 12 can cover houses 1 to 68, and cops in house 52 can cover the rest of the houses. So, there is no safe house.

Example 2 : Cops in house 21 can cover houses 1 to 41, and cops in house 75 can cover houses 55 to 95, leaving houses numbered 42 to 54, and 96 to 100 safe. So, in total 18 houses are safe.
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
 // your code goes here
 int t;
 cin >> t;
 while (t--)
 {
  int m, x, y;
  cin >> m >> x >> y;
  int coverage = x * y;
  int arr[m];
  int house[101];

  for (int i = 1; i <= 100; i++)
  {
   house[i] = 0;
  }
  // for (int i = 1; i <= 100; i++)
  // {
  //  cout << house[i];
  // }
  // cout << endl;

  for (int i = 0; i < m; i++)
  {
   cin >> arr[i];
  }
  // for (int i = 0; i < m; i++)
  // {
  //  cout << arr[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < m; i++)
  {
   int upper_limit = 100;
   int lower_limit = 1;

   int temp1 = arr[i] - coverage;
   if (temp1 <= 1)
   {
    lower_limit = 1;
   }
   else
   {
    lower_limit = arr[i] - coverage;
   }

   int temp2 = arr[i] + coverage;
   if (temp2 >= 100)
   {
    upper_limit = 100;
   }
   else
   {
    upper_limit = arr[i] + coverage;
   }

   for (int j = lower_limit; j <= upper_limit; j++)
   {
    house[j] = 1;
   }

   // cout << "layer " << i << endl;
   // for (int k = 1; k <= 100; k++)
   // {
   //  cout << house[k];
   // }
   // cout << endl;

   // cout << "value of i is " << i << endl;
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++)
  {
   if (house[i] == 0)
   {
    ans++;
   }
  }
  cout << ans << endl;
 }
 return 0;
}
