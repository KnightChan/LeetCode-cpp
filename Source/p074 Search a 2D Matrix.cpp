#include "leetcode.h"

/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]

Given target = 3, return true.

*/


class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;
		if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
		int l = 0, r = m - 1, rowx = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (target >= matrix[mid][0] && target <= matrix[mid][n - 1])
			{
				rowx = mid;
				break;
			}
			if (target < matrix[mid][0])
				r = mid - 1;
			else l = mid + 1;
		}
		if (rowx == -1) return false;
		l = 0; r = n - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (target == matrix[rowx][mid])
				return true;
			if (target < matrix[rowx][mid])
				r = mid - 1;
			else l = mid + 1;
		}
		return false;
	}
};

class Solution2 {
public:
	bool static cmp(const vector<int> &a, const vector<int> &b)
	{
		if (a.size() == 0)
			if (b.size() == 0) return false;
			else return true;
			if (b.size() == 0) return false;
			return a[a.size() - 1] < b[0];
	}

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;
		if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
		vector<int> tar{ target };
		auto iter = lower_bound(matrix.begin(), matrix.end(), tar, cmp);
		int rowx = iter - matrix.begin();
		bool ans = binary_search(matrix[rowx].begin(), matrix[rowx].end(), target);
		return ans;
	}
};

class Solution3 {
public:
	bool static cmp2(const vector<int> &a, const int &b)
	{
		if (a.size() == 0) return true;
		return a[a.size() - 1] < b;
	}

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;
		if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
		vector<int> tar{ target };
		auto iter = lower_bound(matrix.begin(), matrix.end(), target, cmp2);
		int rowx = iter - matrix.begin();
		bool ans = binary_search(matrix[rowx].begin(), matrix[rowx].end(), target);
		return ans;
	}
};

/*
int main()
{
	cout<<Solution2().searchMatrix(vector < vector<int> > {vector < int > {0,1,2}, vector < int > {3,4,5}}, 1);
	return 0;
}
//*/