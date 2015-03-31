#include "leetcode.h"

/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		dfs(n, n, "", ans);
		return ans;
	}

	void dfs(int ln, int rn, string now, vector<string> &ans)
	{
		if (ln + rn == 0)
		{
			ans.push_back(now);
			return;
		}
		if (ln > 0)
			dfs(ln - 1, rn, now + "(", ans);
		if (ln < rn)
			dfs(ln, rn - 1, now + ")", ans);
	}
};

/*
int main()
{
}
//*/