#include "leetcode.h"

/**
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
	bool search(int A[], int n, int target) {
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (target == A[mid])
				return true;
			if (A[low] == A[high])
			{
				++low;
				continue;
			}
			if (A[mid] >= A[low])
				if (target >= A[low] && target < A[mid])
					high = mid - 1;
				else low = mid + 1;
			else
				if (target > A[mid] && target <= A[high])
					low = mid + 1;
				else high = mid - 1;
		}
		return false;
	}
};