#include "leetcode.h"

/**
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


*/

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) return;
		bool colzero = false, rowzero = false;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < n; i++)
			if (matrix[0][i] == 0)
			{
			rowzero = true;
			break;
			}
		for (int i = 0; i < m; i++)
			if (matrix[i][0] == 0)
			{
			colzero = true;
			break;
			}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (matrix[i][j] == 0)
				{
			matrix[0][j] = 0;
			matrix[i][0] = 0;
				}
		for (int i = 1; i < n; i++)
			if (matrix[0][i] == 0)
				setcolzero(i, matrix);

		for (int i = 1; i < m; i++)
			if (matrix[i][0] == 0)
				setrowzero(i, matrix);

		if (colzero) setcolzero(0, matrix);
		if (rowzero) setrowzero(0, matrix);
	}

	void setrowzero(int i, vector<vector<int> > &matrix)
	{
		for (int j = 0; j < matrix[0].size(); j++) matrix[i][j] = 0;
	}

	void setcolzero(int i, vector<vector<int> > &matrix)
	{
		for (int j = 0; j < matrix.size(); j++) matrix[j][i] = 0;
	}
};