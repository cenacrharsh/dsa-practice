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
	int subtractProductAndSum(int n)
	{
		int sum = 0, product = 1;
		while (n > 0)
		{
			int lastDigit = n % 10;
			sum += lastDigit;
			product *= lastDigit;
			n = n / 10;
		}
		return product - sum;
	}
};