#include "leetcode.h"

/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int *dp = new int[s.length()];
		dp[0] = 0;
		int ans = 0;
		for (int i = 1; i < s.length(); i++)
		{
			dp[i] = 0;
			if (s[i] == '(') continue;
			if (s[i - 1] == '(')
				dp[i] = max((i > 1 ? dp[i - 2] + 2 : 2), dp[i]);
			else
			{
				if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					if (i - dp[i - 1] > 1 && s[i - dp[i - 1] - 2] == ')')
						dp[i] += dp[i - dp[i - 1] - 2];
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

class Solution2 {
public:
	int longestValidParentheses(string s) {
		int *dp = new int[s.length()];
		memset(dp, 0, sizeof(int) * s.length());
		int ans = 0;
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				if (s[i - 1] == ')') dp[i] = dp[i - 1];
				continue;
			}
			if (s[i - 1] == '(')
				dp[i] = max(dp[i - 1] + 2, dp[i]);
			else
			{
				if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 1];
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};