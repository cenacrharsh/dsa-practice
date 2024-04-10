#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=i2QrUdwWlak

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end()); // Sort the deck in increasing order

        int n = deck.size();
        vector<int> result(n);
        deque<int> indices;

        for (int i = 0; i < n; i++)
        {
            indices.push_back(i); // Initialize deque with indices 0, 1, 2, ..., n-1
        }

        for (int card : deck)
        {
            int idx = indices.front(); // Get the next available index
            indices.pop_front();       // Remove the index from the front
            result[idx] = card;        // Place the card in the result array

            // Skip next index
            if (!indices.empty())
            {
                indices.push_back(indices.front()); // Move the next index to the end of deque
                indices.pop_front();                // Remove the index from the front
            }
        }

        return result;
    }
};