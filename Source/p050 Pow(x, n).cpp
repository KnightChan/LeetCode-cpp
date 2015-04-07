#include "leetcode.h"

/**
Implement pow(x, n).

*/

class Solution {
public:
	double pow(double x, int n) {
		bool sign = n >= 0;
		double res = 1;
		n = abs(n);
		while (n > 0)
		{
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return sign ? res : 1 / res;
	}
};