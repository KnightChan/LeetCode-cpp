#include "leetcode.h"

/**
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]

*/

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		dfs(0, 0, 0, 0, n, vector<int>(), res);
		return res;
	}

	void dfs(unsigned col, unsigned ls, unsigned rs, int i, int n, vector<int> pos, vector<vector<string> >& res)
	{
		if (i == n)
		{
			res.push_back(construct_ans(pos));
			return;
		}
		unsigned choose = ((1 << n) - 1) & ~(col | ls | rs);
		while (choose)
		{
			unsigned t = choose & ~(choose - 1);
			choose ^= t;
			unsigned k = 0;
			while ((1 << k) != t) k++;
			pos.push_back(n - k - 1);
			dfs(col | t, (ls | t) >> 1, (rs | t) << 1, i + 1, n, pos, res);

			pos.pop_back();
		}
	}

	vector<string> construct_ans(vector<int> pos)
	{
		vector<string> res;
		for (int i = 0; i < pos.size(); i++)
		{
			string s;
			for (int j = 0; j < pos.size(); j++)
				s.push_back('.');
			s[pos[i]] = 'Q';
			res.push_back(s);
		}
		return res;
	}
};

/*
int main()
{
	auto ans = Solution().solveNQueens(4);
	displayVector2(ans);
	return 0;
}
//*/