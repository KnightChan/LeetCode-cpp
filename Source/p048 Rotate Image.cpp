#include "leetcode.h"

/**
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int l = 0, r = n - 1; l < r; ++l, --r)
		{
			int u = l, d = r;
			for (int i = l; i < r; i++)
			{
				int t = matrix[u][i];
				matrix[u][i] = matrix[d - i + u][l];
				matrix[d - i + u][l] = matrix[d][r - i + l];
				matrix[d][r - i + l] = matrix[i][r];
				matrix[i][r] = t;
			}
		}
	}
};