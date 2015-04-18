#include "leetcode.h"


/**
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return 0;
		long long l = 0, r = x;
		while (l <= r)
		{
			long long mid = (l + r) >> 1;
			if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
				return mid;
			if (mid * mid < x)
				l = mid + 1;
			else r = mid - 1;
		}
		return 0;
	}
};