#include "leetcode.h"

/**
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/

class Solution {
public:
	int numDistinct(string s, string t) {
		int ls = s.length(), lt = t.length();
		vector<int> f(lt + 1, 0);
		f[0] = 1;
		for (int i = 0; i < ls; i++)
		{
			for (int j = lt - 1; j >= 0; j--)
				if (s[i] == t[j]) f[j + 1] += f[j];
		}
		return f[lt];
	}
};