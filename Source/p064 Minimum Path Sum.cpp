#include "leetcode.h"

/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


*/

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		vector<int> cnt(n, 0);
		cnt[0] = grid[0][0];
		for (int i = 1; i < n; i++)
			cnt[i] = cnt[i - 1] + grid[0][i];
		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j > 0) cnt[j] = min(cnt[j - 1], cnt[j]);
				cnt[j] += grid[i][j];
			}
		}
		return cnt[n - 1];
	}
};