#include "leetcode.h"

/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int low = 0, high = n - 1;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (A[mid] == target && (mid == 0 || A[mid - 1] != target))
			{
				low = mid;
				break;
			}
			if (target <= A[mid])
				high = mid - 1;
			else low = mid + 1;
		}
		int l = low;
		if (A[l] != target)
			l = -1;
		low = 0, high = n - 1;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (A[mid] == target && (mid == n - 1 || A[mid + 1] != target))
			{
				low = mid;
				break;
			}
			if (target >= A[mid])
				low = mid + 1;
			else high = mid - 1;
		}
		int r = low;
		if (A[r] != target)
			r = -1;
		vector<int> ans;
		ans.push_back(l);
		ans.push_back(r);
		return ans;
	}
};

class Solution2 {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans(2, -1);
		vector<int> a(A, A + n);
		auto iters = equal_range(a.begin(), a.end(), target);
		if (iters.first == a.end() || target < *iters.first) return ans;
		ans[0] = iters.first - a.begin();
		ans[1] = iters.second - a.begin() - 1;
		return ans;
	}
};

class Solution3 {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans(2, -1);
		auto iters = equal_range(A, A + n, target);
		if (iters.first == A + n || target < *iters.first) return ans;
		ans[0] = iters.first - A;
		ans[1] = iters.second - A - 1;
		return ans;
	}
};

/*
int main()
{
	int a[] = { 2, 2 };
	Solution2().searchRange(a, 2, 3);
	Solution3().searchRange(a, 2, 3);
	return 0;
}
//*/