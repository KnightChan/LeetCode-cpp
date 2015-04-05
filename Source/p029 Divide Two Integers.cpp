#include "leetcode.h"

/**
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
		long long a = abs((long long)dividend), b = abs((long long)divisor);
		long long ans = 0;
		while (a >= b)
		{
			long long x = b, m = 1;
			while (a >= x + x) { x += x; m += m; }
			a -= x;
			ans += m;
		}
		ans *= sign;
		if (ans > INT_MAX || ans < INT_MIN) return INT_MAX;
		return ans;
	}
};

/*
int main()
{
	cout << Solution().divide(-1010369383, -2147483648) << endl;
	return 0;
}
//*/