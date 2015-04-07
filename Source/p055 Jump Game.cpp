#include "leetcode.h"

/**
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/

class Solution {
public:
	bool canJump(int A[], int n) {
		int l = 0, r = 0;
		while (l <= r && r < n - 1)
		{
			int newr = r;
			for (int i = l; i <= r; i++)
				newr = max(newr, A[i] + i);
			l = r + 1;
			r = newr;
		}
		if (r >= n - 1) return true;
		return false;
	}
};