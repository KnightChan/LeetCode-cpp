#include "leetcode.h"

/**
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

*/

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0) return 0;
		vector<int> ma;
		for (auto c : matrix[0]) ma.push_back(c - '0');
		int ans = largestRectangleArea(ma);

		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{

				if (matrix[i][j] == '1')
					++ma[j];
				else ma[j] = 0;
			}
			ans = max(ans, largestRectangleArea(ma));
		}
		return ans;
	}

	int largestRectangleArea(vector<int>& height) {
		int ans = 0;
		stack<int> st;
		height.push_back(0);

		for (int i = 0; i < height.size(); i++)
		{
			while (!st.empty() && height[st.top()] > height[i])
			{
				int cur = st.top();
				st.pop();
				int left = st.empty() ? 0 : st.top() + 1;
				ans = max(ans, (i - left) * height[cur]);
			}
			st.push(i);
		}
		return ans;
	}
};