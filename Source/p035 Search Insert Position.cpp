#include "leetcode.h"

/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0

*/

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int low = 0, high = n - 1;
		if (target > A[n - 1])
			return n;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (target <= A[mid] && (mid == 0 || A[mid - 1] < target))
				return mid;
			if (target <= A[mid])
				high = mid - 1;
			else low = mid + 1;
		}
		return low;
	}
};