#include "leetcode.h"

/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0) return 0;
		vector<int> f(s.length() + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= s.length(); i++)
		{
			int one = s[i - 1] - '0';
			int two = one;
			if (i >= 2) two += (s[i - 2] - '0') * 10;
			if (one > 0 && one < 10) f[i] += f[i - 1];
			if (two > 9 && two < 27) f[i] += f[i - 2];
		}
		return f[s.length()];
	}
};