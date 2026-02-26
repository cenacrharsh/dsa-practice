/*
College Life 2 Problem Code: COLGLF2

Chef has just started watching Game of Thrones, and he wants to first calculate the exact time (in minutes) that it'll take him to complete the series.

The series has S seasons, and the ith season has Ei episodes, each of which are Li,1,Li,2,…,Li,Ei minutes long. Note that these Li,j include the duration of the beginning long long intro song in each episode. The streaming service that he uses, allows Chef to skip the long long intro song. The long long intro song changes slightly each season, and so he wants to watch the long long intro song in the first episode of each season, but he'll skip it in all other episodes of that season (yes, we know, a sacrilege!). You know that the long long intro song lasts for Qi minutes in the ith season.

Find the total time in minutes, that he has to watch.

Input:
First line will contain a single long long integer, T, denoting the number of testcases. Then the testcases follow.
The first line of each testcase will contain a single long long integer S, denoting the total number of seasons.
The second line contains S space separated long long integers, Q1,Q2,…,QS, where Qi denotes the duration of the long long intro song in the ith season.
The ith of the next S lines contains Ei+1 space separated long long integers, where the first long long integer is Ei, denoting the number of episodes in the ith season. That is followed by the duration of each of the Ei episodes, Li,1,Li,2,…,Li,Ei.
Output:
For each testcase, output the answer in a single line.

Constralong long ints
1≤T≤5
1≤S≤105
2≤Li,j≤105
1≤Ei
Sum of all Ei in a single testcase is at most 105
1≤Qi<Li,j, for all valid j.
Sample Input 1:
1
2
1 2
1 2
2 3 4
Sample Output 1:
7
Explanation:
1 in the beginning denotes there is only 1 test case.

Testcase 1:

There are 2 seasons. The long long intro song in each of the first season episodes lasts for 1 minute, and the long long intro song in the second season episodes lasts for 2 minutes each.

For the first season, since there is only 1 episode, Chef will be watching it completely - 2 minutes.

For the second season, Chef will be watching the first episode completely (3 minutes) and will skip the long long intro song of the second episode (4−2=2 minutes).

So, the total time spent is 2+(3+(4−2))=7 minutes.

Sample Input 2:
2
1
10
5 11 11 11 11 11
5
10 10 10 10 10
1 11
1 11
1 11
1 11
1 11
Sample Output 2:
15
55
Explanation:
2 in the beginning denotes there are 2 test cases.

Testcase 1:

There is only 1 season having long long intro song for 10 minutes.

Chef will have to watch the entire first episode including the long long intro song and will be skipping the same in further seasons.

So, the total time spent is (11+(11−10)∗4)=15 minutes.

Testcase 2:

There are total 5 seasons. The long long intro song in every season lasts for 10 minutes.

For each of the five seasons, since there is only 1 episode, Chef will be watching all of them completely - 11 minutes each.

So, the total time spent is 11∗5=55 minutes.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long int t;
 cin >> t;
 while (t--)
 {
  long long int s;
  cin >> s;
  long long int intro[s];
  for (long long int i = 0; i < s; i++)
  {
   cin >> intro[i];
  }

  long long int min = 0;
  long long int season = 0;
  while (s--)
  {
   long long int total_ep;
   cin >> total_ep;
   long long int ep_len[total_ep];
   for (long long int i = 0; i < total_ep; i++)
   {
    cin >> ep_len[i];
   }

   for (long long int i = 0; i < total_ep; i++)
   {
    min += (ep_len[i] - intro[season]);
   }

   min += intro[season];
   season++;
  }

  cout << min << endl;
 }
 return 0;
}