#include "leetcode.h"

/**
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/

class Solution {
public:
	vector<string> dfs(string s, vector<vector<int>> &path)
	{
		vector<string> res;
		for (auto x : path[s.length() - 1])
		{
			vector<string> pres;
			if (x) pres = dfs(s.substr(0, x), path);
			auto post = s.substr(x);
			for (auto pre : pres)
				res.push_back(pre + " " + post);
			if (!x) res.push_back(post);
		}
		return res;
	}

	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(1, true);
		vector<vector<int>> path(s.length(), vector<int>());
		for (int i = 0; i < s.length(); i++)
		{
			dp.push_back(false);
			for (int j = 0; j <= i; j++)
			{
				if (wordDict.count(s.substr(j, i - j + 1)) & dp[j])
				{
					dp.back() = true;
					path[i].push_back(j);
				}
			}
		}
		return dfs(s, path);
	}
};

