#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int topRow = 0, bottomRow = m - 1;
        int leftColumn = 0, rightColumn = n - 1;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode *temp = head;
        while (temp != NULL)
        {
            //* fill top row
            for (int col = leftColumn; col <= rightColumn && (temp != NULL); col++)
            {
                ans[topRow][col] = temp->val;
                temp = temp->next;
            }
            topRow++;

            //* fill right col
            for (int row = topRow; row <= bottomRow && (temp != NULL); row++)
            {
                ans[row][rightColumn] = temp->val;
                temp = temp->next;
            }
            rightColumn--;

            //* fill bottom row
            for (int col = rightColumn; col >= leftColumn && (temp != NULL); col--)
            {
                ans[bottomRow][col] = temp->val;
                temp = temp->next;
            }
            bottomRow--;

            //* fill left col
            for (int row = bottomRow; row >= topRow && (temp != NULL); row--)
            {
                ans[row][leftColumn] = temp->val;
                temp = temp->next;
            }
            leftColumn++;
        }
        return ans;
    }
};