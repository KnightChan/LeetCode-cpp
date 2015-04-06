#include "leetcode.h"

/**
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.

*/

class Solution {
public:

	void solveSudoku(vector<vector<char> > &board) {
		int row[9], col[9], cube[9];
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(cube, 0, sizeof(cube));
		stack<pair<int, int>> spaces;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
			{
			if (board[i][j] == '.')
			{
				spaces.push(make_pair(i, j));
				continue;
			}
			int x = board[i][j] - '0';
			x = 1 << x;
			int cubei = i / 3 * 3 + j / 3;
			row[i] |= x;
			col[j] |= x;
			cube[cubei] |= x;
			}
		dfs(board, spaces, row, col, cube);
	}

	bool check(int i, int j, int x, int *row, int *col, int *cube)
	{
		x = 1 << x;
		if (row[i] & x) return false;
		if (col[j] & x) return false;
		int cubei = i / 3 * 3 + j / 3;
		if (cube[cubei] & x) return false;
		return true;
	}

	void change(int i, int j, int x, int *row, int *col, int *cube)
	{
		x = 1 << x;
		int cubei = i / 3 * 3 + j / 3;
		row[i] ^= x;
		col[j] ^= x;
		cube[cubei] ^= x;
	}

	bool dfs(vector<vector<char> > &board, stack<pair<int, int>> spaces, int *row, int *col, int *cube)
	{
		if (spaces.empty())
			return true;
		for (int i = 1; i <= 9; i++)
		{
			auto x = spaces.top();
			if (check(x.first, x.second, i, row, col, cube))
			{
				spaces.pop();
				change(x.first, x.second, i, row, col, cube);
				board[x.first][x.second] = i + '0';
				if (dfs(board, spaces, row, col, cube))
					return true;
				board[x.first][x.second] = '.';
				change(x.first, x.second, i, row, col, cube);
				spaces.push(x);
			}
		}
		return false;
	}
};

/*
int main()
{
	vector<vector<char>> v;
	vector<string> vs = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
	for (string s : vs)
	{
		vector<char> v1;
		for (auto c : s)
			v1.push_back(c);
		v.push_back(v1);
	}
	for (auto v1 : v)
	{
		for (auto c : v1)
			cout << c;
		cout << endl;
	}

	Solution().solveSudoku(v);
	cout << endl;
	for (auto v1 : v)
	{
		for (auto c : v1)
			cout << c;
		cout << endl;
	}
	return 0;
}
//*/