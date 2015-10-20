#include "leetcode.h"

/**
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> candys(n, 1);
		for (int j = 1; j < n; j++)
			if (ratings[j]>ratings[j - 1])
				candys[j] = max(candys[j], candys[j - 1] + 1);
		for (int j = n - 2; j >= 0; j--)
			if (ratings[j]>ratings[j + 1])
				candys[j] = max(candys[j], candys[j + 1] + 1);
		int ans = 0;
		for (int x : candys) ans += x;
		return ans;
	}
};
