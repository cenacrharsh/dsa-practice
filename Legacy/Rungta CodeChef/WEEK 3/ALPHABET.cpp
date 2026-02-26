/*
Studying Alphabet Problem Code: ALPHABET

Not everyone probably knows that Chef has younder brother Jeff. Currently Jeff learns to read.

He knows some subset of the letter of Latin alphabet. In order to help Jeff to study, Chef gave him a book with the text consisting of N words. Jeff can read a word iff it consists only of the letters he knows.

Now Chef is curious about which words his brother will be able to read, and which are not. Please help him!

Input
The first line of the input contains a lowercase Latin letter string S, consisting of the letters Jeff can read. Every letter will appear in S no more than once.

The second line of the input contains an integer N denoting the number of words in the book.

Each of the following N lines contains a single lowecase Latin letter string Wi, denoting the ith word in the book.

Output
For each of the words, output "Yes" (without quotes) in case Jeff can read it, and "No" (without quotes) otherwise.

Constraints
1 ≤ |S| ≤ 26
1 ≤ N ≤ 1000
1 ≤ |Wi| ≤ 12
Each letter will appear in S no more than once.
S, Wi consist only of lowercase Latin letters.
Subtasks
Subtask #1 (31 point): |S| = 1, i.e. Jeff knows only one letter.
Subtask #2 (69 point) : no additional constraints
Example
Input:
act
2
cat
dog

Output:
Yes
No
Explanation
The first word can be read.

The second word contains the letters d, o and g that aren't known by Jeff.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 string s;
 cin >> s;
 int n;
 cin >> n;
 string arr[n];
 for (int i = 0; i < n; i++)
 {
  cin >> arr[i];
 }

 int freq[26] = {0};
 for (int i = 0; i < s.length(); i++)
 {
  freq[s[i] - 'a'] = 1;
 }
 // for (int i = 0; i < 26; i++)
 // {
 //  cout << freq[i];
 // }
 // cout << endl;

 for (int i = 0; i < n; i++)
 {
  bool ans = true;
  int temp_freq[26] = {0};
  for (int j = 0; j < arr[i].length(); j++)
  {
   temp_freq[arr[i][j] - 'a'] = 1;
  }

  // for (int l = 0; l < 26; l++)
  // {
  //  cout << temp_freq[l];
  // }
  // cout << endl;

  for (int k = 0; k < 26; k++)
  {
   if (temp_freq[k] == 1)
   {
    if (freq[k] != 1)
    {
     ans = false;
    }
   }
  }

  cout << (ans ? "Yes" : "No") << endl;
 }
 return 0;
}