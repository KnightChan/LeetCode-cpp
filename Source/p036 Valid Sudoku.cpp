#include "leetcode.h"

/**
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int row[9], col[9], cube[9];
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(cube, 0, sizeof(cube));
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
			{
			if (board[i][j] == '.') continue;
			int x = board[i][j] - '0';
			x = 1 << x;
			if (row[i] & x) return false;
			if (col[j] & x) return false;
			int cubei = i / 3 * 3 + j / 3;
			if (cube[cubei] & x) return false;
			row[i] |= x;
			col[j] |= x;
			cube[cubei] |= x;
			}
		return true;
	}
};