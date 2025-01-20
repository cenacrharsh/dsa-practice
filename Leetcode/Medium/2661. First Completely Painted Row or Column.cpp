#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
  {
    //* everytime we encounter an element we bump that [row, col] position number by 1 and if any field value reaches it's row or col number we know that the row or col was filled
    unordered_map<int, int> rowPos, colPos, rowCount, colCount;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        rowPos[mat[i][j]] = i;
        colPos[mat[i][j]] = j;
      }
    }

    for (int i = 0; i < arr.size(); i++)
    {
      int val = arr[i];
      rowCount[rowPos[val]]++;
      colCount[colPos[val]]++;

      //* eg. if row[0] value becomes = n we know that all n elements in that row have been visited
      if (rowCount[rowPos[val]] == n || colCount[colPos[val]] == m)
      {
        return i;
      }
    }

    return -1;
  }
};