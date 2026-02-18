#include <iostream>
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
    vector<int> generateRow(int row)
    {
        vector<int> ansRow;
        long long res = 1;
        ansRow.push_back(res);
        for (int col = 1; col < row; col++)
        {
            res = res * (row - col);
            res = res / col;
            ansRow.push_back(res);
        }
        return ansRow;
    }

    vector<int> getRow(int rowIndex)
    {
        return generateRow(rowIndex + 1);
    }
};