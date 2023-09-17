#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=W2hhdHsGOUM

//! Using Vector

/*
> Time Complexity: O(1)
> Space Complexity: O(n)
*/

class BrowserHistory
{
public:
 vector<string> history;
 int curr;

 BrowserHistory(string homepage)
 {
  history.push_back(homepage);
  curr = 0;
 }

 void visit(string url)
 {
  // clear all data stored in indexes ahead of curr
  history.erase(history.begin() + curr + 1, history.end());

  // add the new url to history
  history.push_back(url);
  curr++;
 }

 string back(int steps)
 {
  // we can't go lower than index 0
  curr = max(0, curr - steps);
  return history[curr];
 }

 string forward(int steps)
 {
  // we can't go higher than size of vector
  curr = min((int)(history.size() - 1), curr + steps);
  return history[curr];
 }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */