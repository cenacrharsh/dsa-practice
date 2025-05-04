#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(2 * N) => for N next() calls, not individual, as we know it takes 2N time to calculate N previous greater elements
> Space Complexity: O(N) => max elements that can be stored in stack is N for N next calls
*/

//* Previous Greater Element
//* For every element we can't traverse back in the error to figure out the index of the previous greater element than current element so we'll maintain a stack to store the previous greater element's index

class StockSpanner
{
public:
  stack<pair<int, int>> st; //* element->index
  int currentIndex;

  StockSpanner()
  {
    currentIndex = -1;
  }

  int next(int price)
  {
    currentIndex++;
    //* pop all smaller or equal elements than price because they are not it's prev greater element nor will they be for any coming elements as price would come first
    while (!st.empty() && price >= st.top().first)
    {
      st.pop();
    }
    int span = currentIndex - (!st.empty() ? st.top().second : -1);
    st.push({price, currentIndex});
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */