#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
 *	@params:
 *		marks1 = A vector denoting the marks of first row students
 *		marks2 = A vector denoting the marks of second row students
 *
 *	@return:
 *		A vector of size (n + m), after merging the students in two rows
 */
vector<int> mergeStudents(vector<int> marks1, vector<int> marks2)
{
 // Write your code here
 int n = marks1.size();
 int m = marks2.size();
 vector<int> ans(n + m);
 int i = 0, j = 0, k = 0;
 while (i < n && j < m)
 {
  if (marks1[i] >= marks2[j])
  {
   ans[k++] = marks1[i++];
  }
  else
  {
   ans[k++] = marks2[j++];
  }
 }
 while (i < n)
 {
  ans[k++] = marks1[i++];
 }
 while (j < m)
 {
  ans[k++] = marks2[j++];
 }
 return ans;
}
