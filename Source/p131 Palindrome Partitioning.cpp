#include "leetcode.h"

/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
	void dfs(string s, int start, vector<string> cur, vector<vector<bool>> &is_pal, vector<vector<string>> &res)
	{
		if (start == s.length())
		{
			res.push_back(cur);
			return;
		}
		for (int i = start; i < s.length(); i++)
		{
			if (is_pal[start][i - start + 1])
			{
				cur.push_back(s.substr(start, i - start + 1));
				dfs(s, i + 1, cur, is_pal, res);
				cur.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<bool>> is_pal(s.length(), vector<bool>(s.length(), false));
		for (int i = s.length() - 1; i >= 0; i--)
			for (int l = 0; l <= s.length() - i; l++)
				is_pal[i][l] = l<2 ? true : (is_pal[i + 1][l - 2] & s[i] == s[i + l - 1]);
		vector<vector<string>> res;
		vector<string> cur;
		dfs(s, 0, cur, is_pal, res);
		return res;
	}
};

