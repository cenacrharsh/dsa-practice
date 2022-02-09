/*
Chef and Rainbow Array Problem Code: RAINBOWA

Chef likes all arrays equally. But he likes some arrays more equally than others. In particular, he loves Rainbow Arrays.

An array is Rainbow if it has the following structure:

First a1 elements equal 1.
Next a2 elements equal 2.
Next a3 elements equal 3.
Next a4 elements equal 4.
Next a5 elements equal 5.
Next a6 elements equal 6.
Next a7 elements equal 7.
Next a6 elements equal 6.
Next a5 elements equal 5.
Next a4 elements equal 4.
Next a3 elements equal 3.
Next a2 elements equal 2.
Next a1 elements equal 1.
ai can be any non-zero positive integer.
There are no other elements in array.

Help Chef in finding out if the given array is a Rainbow Array or not.

Input
The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains an integer N, denoting the number of elements in the given array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array.
Output
For each test case, output a line containing "yes" or "no" (without quotes) corresponding to the case if the array is rainbow array or not.
Constraints
1 ≤ T ≤ 100
7 ≤ N ≤ 100
1 ≤ Ai ≤ 10
Subtasks
Subtask 1 (100 points) : Original constraints
Example
Input
3
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
14
1 2 3 4 5 6 7 6 5 4 3 2 1 1
13
1 2 3 4 5 6 8 6 5 4 3 2 1

Output
yes
no
no
Explanation
The first example satisfies all the conditions.

The second example has 1 element of value 1 at the beginning and 2 elements of value 1 at the end.

The third one has no elements with value 7 after elements with value 6.
*/

/*
1 - count freq of each element
2 - all elements should be < 6
3 - for elements 1-6, freq should be even
4 - no freq should be zero
5 - we create our rainbow array
6 - compare index wise with original array
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> get_rainbow(vector<int> &freq)
{
 vector<int> rainbow;
 for (int i = 1; i <= 6; i++)
 {
  int cnt = freq[i] / 2;
  freq[i] = freq[i] / 2;
  for (int j = 1; j <= cnt; j++)
  {
   rainbow.push_back(i);
  }
 }

 for (int j = 1; j <= freq[7]; j++)
 {
  rainbow.push_back(7);
 }
 freq[7] = 0;

 for (int i = 6; i >= 1; i--)
 {
  int cnt = freq[i];
  for (int j = 0; j < cnt; j++)
  {
   rainbow.push_back(i);
  }
  freq[i] = 0;
 }

 return rainbow;
}

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  int original_arr[n];
  vector<int> freq(11, 0);
  bool isRainbow = true;
  for (int i = 0; i < n; i++)
  {
   cin >> original_arr[i];
   freq[original_arr[i]]++;

   if (original_arr[i] > 7 || original_arr[i] < 1)
   {
    isRainbow = false;
   }
  }

  for (int i = 1; i < 6; i++)
  {
   if (freq[i] % 2 == 1 || freq[i] == 0)
   {
    isRainbow = false;
   }
  }

  if (freq[7] == 0)
  {
   isRainbow = false;
  }

  vector<int> rainbow_arr = get_rainbow(freq);

  for (int i = 0; i < n; i++)
  {
   if (original_arr[i] != rainbow_arr[i])
   {
    isRainbow = false;
   }
  }

  if (!isRainbow)
  {
   cout << "no" << endl;
  }
  else
  {
   cout << "yes" << endl;
  }
 }
 return 0;
}