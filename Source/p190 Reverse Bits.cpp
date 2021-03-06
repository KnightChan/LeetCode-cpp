#include "leetcode.h"

/**
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


*/

class Solution {
public:
	uint32_t reverseBits1(uint32_t n) {
		uint32_t ans = 0;
		while (n)
		{
			uint32_t t = n ^ (n & (n - 1));
			n &= n - 1;
			ans += (1 << 31) / t;
		}
		return ans;
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		for (unsigned i = 0; i< 32; ++i, n = n >> 1)
			ans = (ans << 1) + (n & 1);
		return ans;
	}
};