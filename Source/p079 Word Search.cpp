#include "leetcode.h"

/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (word.length() == 0) return true;
		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		if (n == 0) return false;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (dfs(i, j, board, word))
					return true;
		return false;
	}

	bool check(int x, int y, int m, int n)
	{
		if (x < 0 || x >= m) return false;
		if (y < 0 || y >= n) return false;
		return true;
	}

	bool dfs(int x, int y, vector<vector<char> > &board, string word) {
		static int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
		if (!check(x, y, board.size(), board[0].size()) || word[0] != board[x][y]) return false;
		if (word.length() == 1) return true;
		char ch = board[x][y];
		board[x][y] = '~';
		for (int i = 0; i < 4; i++)
		{
			if (dfs(x + dir[i][0], y + dir[i][1], board, word.substr(1, word.size() - 1)))
				return true;
		}
		board[x][y] = ch;
		return false;
	}
};