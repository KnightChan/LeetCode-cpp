#include "leetcode.h"

/**
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?


*/

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		if (!n) return 0;
		if (citations[0] >= n) return n;
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (citations[mid] <= n - mid - 1 && (mid == n - 1 || citations[mid + 1] >= n - mid - 1))
			{
				if (citations[mid] >= n - mid)
				{
					r = mid - 1;
					continue;
				}
				return n - mid - 1;
			}

			if (citations[mid] >= n - mid - 1)
				r = mid - 1;
			else l = mid + 1;
		}
		return n - l - 1;
	}
};

class Solution1 {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		if (!n) return 0;
		int h = 0;
		int l = 0, r = n;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (citations[n - mid - 1] > mid)
			{
				l = mid + 1;
				h = l;
			}
			else r = mid - 1;
		}
		return h;
	}
};

