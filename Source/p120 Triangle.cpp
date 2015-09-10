#include "leetcode.h"

/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0) return 0;
		vector<int> res(triangle.size(), INT_MAX);
		res[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++)
		{
			for (int j = triangle[i].size() - 1; j > 0; j--)
			{
				res[j] = min(res[j], res[j - 1]) + triangle[i][j];
			}
			res[0] += triangle[i][0];
		}
		int ans = res[0];
		for (int i = 1; i < res.size(); i++)
			ans = min(ans, res[i]);
		return ans;
	}
};
