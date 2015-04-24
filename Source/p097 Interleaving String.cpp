#include "leetcode.h"


/**
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
		if (l1 + l2 != l3) return false;
		vector<vector<bool>> f(l1 + 1, vector<bool>(l2 + 1, false));
		f[0][0] = true;
		for (int i = 0; i < l1 + 1; i++)
			for (int j = 0; j < l2 + 1; j++)
			{
			if (i > 0 && f[i - 1][j] && s1[i - 1] == s3[i + j - 1]) f[i][j] = true;
			if (j > 0 && f[i][j - 1] && s2[j - 1] == s3[i + j - 1]) f[i][j] = true;
			}
		return f[l1][l2];
	}
};