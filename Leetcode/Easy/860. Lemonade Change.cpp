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
    bool lemonadeChange(vector<int> &bills)
    {
        int fiveDollarBills = 0, tenDollarBills = 0, twentyDollarBills = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fiveDollarBills++;
            }
            else if (bills[i] == 10)
            {
                if (fiveDollarBills == 0)
                {
                    return false;
                }
                else
                {
                    fiveDollarBills--;
                    tenDollarBills++;
                }
            }
            else if (bills[i] == 20)
            {
                if (fiveDollarBills >= 1 && tenDollarBills >= 1)
                {
                    fiveDollarBills--;
                    tenDollarBills--;
                    twentyDollarBills++;
                }
                else if (fiveDollarBills >= 3)
                {
                    fiveDollarBills -= 3;
                    twentyDollarBills++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};