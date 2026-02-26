#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define M 6
#define N 6

/*
 *  Complete the below function.
 *  return 1 if the word is found, else return 0
 */
int searchWord(char board[M][N], char word[], int i, int j, int m, int n, int index, bool visited[M][N])
{
 int wordLen;
 for (wordLen = 0; word[wordLen] != '\0'; wordLen++)
  ;
 if (index == wordLen)
 {
  return 1;
 }

 //* checking the bounds of matrix
 if (i < 0 || j < 0 || i >= m || j >= n)
 {
  return 0;
 }

 if (board[i][j] != word[index] || visited[i][j] == true)
 {
  return 0;
 }

 visited[i][j] = true;

 if (searchWord(board, word, i - 1, j, m, n, index + 1, visited) ||
     searchWord(board, word, i + 1, j, m, n, index + 1, visited) ||
     searchWord(board, word, i, j - 1, m, n, index + 1, visited) ||
     searchWord(board, word, i, j + 1, m, n, index + 1, visited))
 {
  return 1;
 }

 visited[i][j] = false;
 return 0;
}

int isFound(char board[M][N], char word[], int m, int n)
{
 // Write your code here
 bool visited[M][N];
 for (int i = 0; i < M; i++)
 {
  for (int j = 0; j < N; j++)
  {
   visited[i][j] = false;
  }
 }

 for (int i = 0; i < m; i++)
 {
  for (int j = 0; j < n; j++)
  {
   if (board[i][j] == word[0])
   {
    //* found the first letter of the word, now we try to mark it as visited
    if (searchWord(board, word, i, j, m, n, 0, visited))
    {
     return 1;
    }
   }
  }
 }
 return 0;
}

int main()
{
 int m, n;
 cin >> m >> n;

 char board[M][N];
 for (int i = 0; i < m; i++)
  cin >> board[i];

 char word[30];
 cin >> word;

 if (isFound(board, word, m, n))
  cout << "Found";
 else
  cout << "Not Found";

 return 0;
}