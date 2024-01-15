#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> m; //* {player, loss}
        for (int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if (m.find(winner) == m.end())
            {
                m[winner] = 0;
            }
            m[loser]++;
        }
        vector<int> zeroLoss, oneLoss;
        for (auto [player, losses] : m)
        {
            if (losses == 0)
            {
                zeroLoss.push_back(player);
            }
            else if (losses == 1)
            {
                oneLoss.push_back(player);
            }
        }
        return {zeroLoss, oneLoss};
    }
};