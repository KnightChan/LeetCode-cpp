#include "leetcode.h"

/**
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		if (matrix.size() == 0) return ans;
		for (int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1; u <= d && l <= r; ++u, --d, ++l, --r)
			circle(l, r, u, d, matrix, ans);
		return ans;
	}

	void circle(int l, int r, int u, int d, vector<vector<int> > &matrix, vector<int> &ans)
	{
		if (l > r || u > d) return;
		for (int i = l; i <= r; i++)
			ans.push_back(matrix[u][i]);
		for (int i = u + 1; i <= d; i++)
			ans.push_back(matrix[i][r]);
		if (l == r || u == d) return;
		for (int i = r - 1; i >= l; i--)
			ans.push_back(matrix[d][i]);
		for (int i = d - 1; i > u; i--)
			ans.push_back(matrix[i][l]);
	}
};