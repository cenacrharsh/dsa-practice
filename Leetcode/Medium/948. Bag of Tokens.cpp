#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=prI82maTivg

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(1)
*/

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        //* all tokens when played up or down give +-1 score, so we aim to play higher valued token face down rather than lower values ones as in both cases we get -1 but higher token gives us more power to play other cards face up
        //* greedy sol without maxScore won't work because even if it's last token we might end up playing face down to gain power and loose score even though no more tokens are left to use that power and maximise score, so we maintain maxScore to keep track of max value we can go to

        int score = 0;
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        while (left <= right)
        {
            if (power >= tokens[left])
            {
                power -= tokens[left++];
                score++;
            }
            else if (power < tokens[left])
            {
                if (score > 0)
                {
                    power += tokens[right--];
                    score--;
                }
                else
                {
                    break;
                }
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};