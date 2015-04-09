#include "leetcode.h"

/**
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]


*/

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > ans;
		int index = 1;
		for (int i = 0; i < n; i++)
			ans.push_back(vector<int>(n));
		for (int l = 0, r = n - 1; l <= r; ++l, --r)
			setCube(l, r, l, r, index, ans);
		return ans;
	}

	void setCube(int l, int r, int u, int d, int &start, vector<vector<int> > &a)
	{
		for (int i = l; i <= r; i++)
			a[u][i] = start++;
		for (int i = u + 1; i <= d; i++)
			a[i][r] = start++;
		if (l == r) return;
		for (int i = r - 1; i >= l; i--)
			a[d][i] = start++;
		for (int i = d - 1; i > l; i--)
			a[i][l] = start++;
	}
};