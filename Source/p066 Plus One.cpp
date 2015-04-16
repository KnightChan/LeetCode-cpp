#include "leetcode.h"


/**
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits.back() += 1;
		int n = digits.size() - 1;
		while (n > 0 && digits[n] > 9)
		{
			digits[n - 1] += digits[n] / 10;
			digits[n--] %= 10;
		}
		if (digits[0] > 9)
		{
			digits.insert(digits.begin(), digits[0] / 10);
			digits[1] %= 10;
		}
		return digits;
	}
};