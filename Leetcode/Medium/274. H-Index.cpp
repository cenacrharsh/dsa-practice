#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ydiAVn7bm6g

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> freq(n + 1, 0);

        for (int citation : citations)
        {
            if (citation >= n)
            {
                freq[n]++;
            }
            else
            {
                freq[citation]++;
            }
        }

        int totalBooks = 0;
        for (int i = n; i >= 0; i--)
        {
            totalBooks += freq[i];

            if (totalBooks >= i)
            {
                return i;
            }
        }

        return 0;
    }
};
