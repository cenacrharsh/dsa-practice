#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int c[] = {20, 50, 100, 200, 500};

class ATM
{
public:
 vector<long long> a;
 ATM() : a(5)
 {
 }

 void deposit(vector<int> banknotesCount)
 {
  for (int i = 0; i < 5; ++i)
   a[i] += banknotesCount[i];
 }

 vector<int> withdraw(int amount)
 {
  vector<int> res(5);
  for (int i = 4; i >= 0; --i)
  {
   int tmp = min<long long>(amount / c[i], a[i]);
   res[i] = tmp;
   amount -= tmp * c[i];
  }
  if (amount != 0)
   return {-1};
  for (int i = 0; i < 5; ++i)
   a[i] -= res[i];
  return res;
 }
};

//! Contest Sol - Using Hashmap

class ATM
{
public:
 unordered_map<long long int, long long int> notes;

 ATM()
 {
  notes[20] = 0;
  notes[50] = 0;
  notes[100] = 0;
  notes[200] = 0;
  notes[500] = 0;
 }

 void deposit(vector<int> banknotesCount)
 {
  notes[20] += banknotesCount[0];
  notes[50] += banknotesCount[1];
  notes[100] += banknotesCount[2];
  notes[200] += banknotesCount[3];
  notes[500] += banknotesCount[4];
 }

 vector<int> withdraw(int amount)
 {
  vector<int> ans;
  long long int n, minN;
  int n20 = 0, n50 = 0, n100 = 0, n200 = 0, n500 = 0;

  n = amount / 500;
  minN = min(n, notes[500]);
  notes[500] -= minN;
  n500 += minN;
  amount = amount - (500 * minN);

  n = amount / 200;
  minN = min(n, notes[200]);
  notes[200] -= minN;
  n200 += minN;
  amount = amount - (200 * minN);

  n = amount / 100;
  minN = min(n, notes[100]);
  notes[100] -= minN;
  n100 += minN;
  amount = amount - (100 * minN);

  n = amount / 50;
  minN = min(n, notes[50]);
  notes[50] -= minN;
  n50 += minN;
  amount = amount - (50 * minN);

  n = amount / 20;
  minN = min(n, notes[20]);
  notes[20] -= minN;
  n20 += minN;
  amount = amount - (20 * minN);

  if (amount != 0)
  {
   ans.push_back(-1);
   notes[20] += n20;
   notes[50] += n50;
   notes[100] += n100;
   notes[200] += n200;
   notes[500] += n500;
   return ans;
  }

  ans.push_back(n20);
  ans.push_back(n50);
  ans.push_back(n100);
  ans.push_back(n200);
  ans.push_back(n500);

  return ans;
 }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */