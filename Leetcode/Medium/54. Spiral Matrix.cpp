#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Better Approach
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int rowStart = 0, rowEnd = n - 1,
            colStart = 0, colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            //* for first row
            for (int i = colStart; i <= colEnd; i++)
            {
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            //* for last col
            for (int i = rowStart; i <= rowEnd; i++)
            {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            if (rowStart <= rowEnd)
            {
                //* for last row
                for (int i = colEnd; i >= colStart; i--)
                {
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            if (colStart <= colEnd)
            {
                //* for first col
                for (int i = rowEnd; i >= rowStart; i--)
                {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return ans;
    }
};

//! Another Approach

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0, down = r - 1, left = 0, right = c - 1;
        int dir = 0;
        vector<int> ans;
        while (top <= down && left <= right)
        {
            if (dir == 0)
            {
                for (int i = top; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
                dir = 1;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir = 2;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
                dir = 3;
            }
            else if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir = 0;
            }
        }
        return ans;
    }
};