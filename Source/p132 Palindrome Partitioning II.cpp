#include "leetcode.h"

/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
	int minCut(string s) {
		vector<vector<bool>> is_pal(s.length(), vector<bool>(s.length(), false));
		for (int i = s.length() - 1; i >= 0; i--)
			for (int l = 0; l <= s.length() - i; l++)
				is_pal[i][l] = l<2 ? true : (is_pal[i + 1][l - 2] & s[i] == s[i + l - 1]);
		vector<int> dp(s.length(), INT_MAX >> 1);
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j <= i; j++)
				dp[i] = min(dp[i], is_pal[j][i - j + 1] ? (j>0 ? dp[j - 1] + 1 : 0) : (INT_MAX >> 1));
		return dp[s.length() - 1];
	}
};
