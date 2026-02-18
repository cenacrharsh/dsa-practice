#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimised Row Generation

/*
> Time Complexity: O(N * N) => O(N) for generation of each row
> Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        //* Row 6 : 1 5 10 5 1 => 1 * 5/1 * (5/1 * 4/2) * (5/1 * 4/2 * 3/3) * (5/1 * 4/2 * 3/3 * 2/4) * (5/1 * 4/2 * 3/3 * 2/4 * 1/5)
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

//! Brute Force, Using nCr for each element of pascal triangle

/*
> Time Complexity: O(N * N * R)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int nCr(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++)
        {
            vector<int> temp;
            for (int i = 1; i <= row; i++)
            {
                temp.push_back(nCr(row - 1, i - 1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//! Using Sum of last 2 elements

/*
> Time Complexity: O(N^2) => N*(N+1)/2
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        // value of (i, j)th element = i-1Cj-1 (nCr), as we follow 0 based indexing hence -1
        // calculate value of [n * (n-1) *---* (n-k+1)]
        /*
        for(int i = 0; i < k; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        */
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            // we know each row has elements = row number
            ans[i].resize(i + 1);

            // we also know first and last element of each row = 1
            ans[i][0] = ans[i][i] = 1;

            // traverse from 2nd element, to 2nd last element
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};