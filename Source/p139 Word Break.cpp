#include "leetcode.h"

/**
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".


*/

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(1, true);
		for (int i = 0; i < s.length(); i++)
		{
			dp.push_back(false);
			for (int j = 0; j <= i; j++)
				dp.back() = dp.back() | (wordDict.count(s.substr(j, i - j + 1)) & dp[j]);
		}
		return dp[s.length()];
	}
};

