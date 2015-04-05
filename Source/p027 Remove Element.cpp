#include "leetcode.h"

/**
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int l = 0, r = n - 1;
		while (l <= r)
		{
			while (l <= r && A[l] != elem) ++l;
			while (l <= r && A[r] == elem) --r;
			if (l < r)
				A[l++] = A[r--];
		}
		return r + 1;
	}
};