/*
Holi and Miss Ural Problem Code: HOLIURAL

Statement
In a far away Galaxy of Tilky Way, there was a planet Tarth where the sport of Tompetitive Toding was very popular. According to legends, there lived a setter known for making long problem statements on Holi.

Miss Ural wants to buy colors for Holi, and that too, at the cheapest cost!!

There are N shops selling colors near Ural's house, where the i′th shop sells colors at rate of Ri for one unit. Also, i′th shop is located at a distance of Di kilometers from her house. Life was simple, but then petrol and fuel prices soared up. The current price of petrol to travel one kilometer is K.

Find the minimum cost at which Miss Ural can buy one unit of color. Note that she does not need to return back home.

Input:
The first line of input contains T, number of test cases in a file.
The next line contains two integers, N and K, as described in the problem statement.
The next line contains N space separated integers, denoting Di, i.e. distance of the shop.
The next line contains N space separated integers denoting Ri, i.e. rate of the color.
Output:
For test case, output minimum cost to purchase 1 unit of color.

Constraints
1≤T≤105
1≤N≤105
Sum of N over all T in a test file does not exceed 106.
1≤Ri,K,Di≤109
Subtasks
100% points - Original Constraints

Sample Input:
2
3 10
1 2 3
3 2 1
3 1
2 4 6
3 2 1

Sample Output:
13
5

EXPLANATION:
In first case, K=10. He can buy from first shop, at cost of 1∗10+3=13. Recall that the first array denotes distance.

For second case, shop 1 offers best deal.
*/

#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int main()
{
 // your code goes here
 long long int t;
 cin >> t;
 while (t--)
 {
  long long int n, k;
  cin >> n >> k;

  long long int dist[n];
  for (int i = 0; i < n; i++)
  {
   cin >> dist[i];
  }

  long long int rate[n];
  for (int i = 0; i < n; i++)
  {
   cin >> rate[i];
  }

  long long int min_cost = INT64_MAX;
  long long int temp_cost = 0;

  for (int i = 0; i < n; i++)
  {
   temp_cost = (dist[i] * k) + rate[i];
   min_cost = min(min_cost, temp_cost);
   temp_cost = 0;
  }

  cout << min_cost << endl;
 }
 return 0;
}
