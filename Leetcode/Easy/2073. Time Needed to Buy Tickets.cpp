#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        //* the contribution of all elements to the left of index k contribute min(tickets[i], tickets[k]) and the elements to the right of index k contriubte min(tickets[i], tickets[k] - 1) since we always reach to the right of index k after having decrementd 1
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
            {
                ans += min(tickets[i], tickets[k]);
            }
            else
            {
                ans += min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
};

//> or

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;
        while (tickets[k] != 0)
        {
            for (int i = 0; i < tickets.size(); i++)
            {
                if (tickets[i] > 0)
                {
                    ans++;
                }
                tickets[i]--;
                if (tickets[k] == 0)
                {
                    return ans;
                }
            }
        }
        return -1;
    }
};