#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Unordered Map & Priority Queue
class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> freq;      //* char -> freq
    priority_queue<pair<int, char>> pq; //* freq -> char max heap (for sorting)

    for (char ch : s)
    {
      freq[ch]++;
    }

    for (auto [ch, count] : freq)
    {
      pq.push({count, ch});
    }

    string ans = "";
    while (!pq.empty())
    {
      // pair<int, char> temp = pq.top();
      // while(temp.first--) {
      //     ans += temp.second;
      // }

      auto [count, ch] = pq.top();
      ans.append(count, ch);
      pq.pop();
    }
    return ans;
  }
};

// # Tutorial: https://www.youtube.com/watch?v=4Vu626AoElw

//! Using Hashmap & Vectors

class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> freq;
    vector<string> bucket(s.size() + 1, "");
    string ans;
    for (char c : s)
    {
      freq[c]++;
    }
    for (auto &it : freq)
    {
      int n = it.second;
      char c = it.first;
      bucket[n].append(n, c); // append char c n times at Nth position in vector
    }
    for (int i = s.size(); i >= 0; i--)
    {
      if (!bucket[i].empty())
      {
        ans.append(bucket[i]);
      }
    }
    return ans;
  }
};

// # Tutorial: https://www.youtube.com/watch?v=tbJt-0oazp4, https://www.youtube.com/watch?v=trFw8IDw2Vg,

//! Using Hashmap & Priority Queues

class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> freq; // char, int
    for (int i = 0; i < s.size(); i++)
    {
      freq[s[i]]++;
    }
    priority_queue<pair<int, char>> pq; // int, char so heapify func is called on int

    for (int i = 0; i < s.size(); i++)
    {
      pq.push({freq[s[i]], s[i]});
    }

    string ans = "";
    while (!pq.empty())
    {
      ans += pq.top().second;
      pq.pop();
    }
    return ans;
  }
};

// # Tutorial: https://www.youtube.com/watch?v=vltY5jxqcco

//! Using Array of Pairs

/*
> Time Complexity: O(123 log 123 + n)
> Space Complexity: O(n)
*/

class Solution
{
public:
  string frequencySort(string s)
  {
    vector<pair<int, char>> hash('z' + 1, {0, 0});
    //* vector of size 123 (z = 122) and filling all array of pairs with default value {0, 0}

    for (auto c : s)
    {
      hash[c] = {hash[c].first + 1, c};
    }

    // sorting in ascending order
    sort(hash.begin(), hash.end());

    string res = "";

    for (auto p : hash)
    {
      res = string(p.first, p.second) + res;
      // since sorted in asc order, we add in front
      // also + is a costly operation of O(l1 + l2), hence we use string(3, a) -> aaa
    }
    return res;
  }
};