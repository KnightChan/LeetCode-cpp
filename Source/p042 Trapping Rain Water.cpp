#include "leetcode.h"

/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
class Solution {
public:
	int trap(int A[], int n) {
		if (n == 0)
			return 0;
		int area = 0, maxi = -1, maxv = -1;
		for (int i = 0; i < n; i++)
			if (A[i] > maxv){
			maxi = i;
			maxv = A[i];
			}
		area += findArea(A, n, maxi);
		area += findAreaReverse(A, n, maxi);
		return area;
	}

	int findArea(int A[], int n, int maxi)
	{
		int this_high = A[0], i = 0, area = 0;
		while (i < maxi)
		{
			while (i < maxi
				&& A[i] <= this_high)
			{
				area += this_high - A[i];
				++i;
			}
			this_high = A[i];
		}
		return area;
	}

	int findAreaReverse(int A[], int n, int maxi)
	{
		int this_high = A[n - 1], i = n - 1, area = 0;
		while (i > maxi)
		{
			while (i > maxi
				&& A[i] <= this_high)
			{
				area += this_high - A[i];
				--i;
			}
			this_high = A[i];
		}
		return area;
	}
};

class Solution1 {
public:
	int trap(int height[], int n) {
		stack<pair<int, int>> stk;
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			while (stk.size()>0 && stk.top().first <= height[i])
			{
				int h = stk.top().first;
				stk.pop();
				if (!stk.empty())
				{
					int l = i - stk.top().second - 1;
					h = min(stk.top().first, height[i]) - h;
					result += h*l;
				}
			}
			stk.push(pair<int, int>(height[i], i));
		}
		return result;
	}
};