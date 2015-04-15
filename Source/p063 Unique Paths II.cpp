#include "leetcode.h"

/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.


*/


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0) return 0;
		int n = obstacleGrid[0].size();
		vector<int> cnt(n, 0);
		if (obstacleGrid[0][0] == 0) cnt[0] = 1;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 0)
				{
					if (j > 0) cnt[j] += cnt[j - 1];
				}
				else cnt[j] = 0;
			}
		}
		return cnt[n - 1];
	}
};