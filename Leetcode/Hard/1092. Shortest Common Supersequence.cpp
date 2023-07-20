#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=15

//- length of smallest supersequence = n + m - LCS(n, m), because between the 2 stirngs the common part in taken only once so to minimize the supersequence length we maximize the comman part hence LCS of the 2 strings