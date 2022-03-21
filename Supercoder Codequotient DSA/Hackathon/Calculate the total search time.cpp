#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(k * log n)
> Space Complexity: O(1)
*/

// CLOCKWISE ROTATION - LEFT SHIFT
// DECREASING ORDER OF ELEMENTS
long searchTime(int N, int book_IDs[], int bookID)
{
 // Write your code here
 int l = 0, r = N - 1;
 while (l <= r)
 {
  int mid = (l + r) / 2;
  // if we find the bookID at middle index itself
  if (bookID == book_IDs[mid])
  {
   return mid;
  }
  // left halve is sorted
  else if (book_IDs[l] >= book_IDs[mid])
  {
   // if bookID lies in range from l -> mid - 1, else it lies in range mid + 1 -> r
   if (bookID <= book_IDs[l] && bookID > book_IDs[mid])
   {
    r = mid - 1;
   }
   else
   {
    l = mid + 1;
   }
  }
  // right halve is sorted
  else if (book_IDs[mid] >= book_IDs[r])
  {
   // if bookID lies in range from mid + 1 -> r, else it lies in range l -> mid - 1
   if (bookID < book_IDs[mid] && bookID >= book_IDs[r])
   {
    l = mid + 1;
   }
   else
   {
    r = mid - 1;
   }
  }
 }
 return -1;
}

long totalSearchTime(int N, int book_IDs[], int K, int booksToFind[])
{
 // Write your code here
 long totalSearchTime = 0;
 for (int i = 0; i < K; i++)
 {
  long time = searchTime(N, book_IDs, booksToFind[i]);
  time = (time < 0) ? N : time;
  totalSearchTime += time;
 }
 return totalSearchTime;
}