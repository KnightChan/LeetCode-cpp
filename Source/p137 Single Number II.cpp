#include "leetcode.h"

/**
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> one, two, three;
		for (auto x : nums)
		{
			if (three.count(x)) three.erase(x);
			else if (two.count(x))
			{
				two.erase(x);
				three.insert(x);
			}
			else if (one.count(x))
			{
				one.erase(x);
				two.insert(x);
			}
			else
			{
				one.insert(x);
			}
		}
		for (auto x : one)
			return x;
	}
};

class Solution {
public:
	int singleNumber(vector<int> nums) {
		int ones = 0, twos = 0;
		for (auto x : nums)
		{
			ones = (ones ^ x) & ~twos;
			twos = (twos ^ x) & ~ones;
		}
		return ones;
	}
};

