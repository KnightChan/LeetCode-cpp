#include "leetcode.h"

/**
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/

class Solution {
public:
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

/*
int main()
{
	cout << Solution().largestRectangleArea(vector < int > {4, 2}) << endl;
	return 0;
}
//*/