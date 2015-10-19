#include "leetcode.h"

/**
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/

class Solution {
public:
	vector<pair<int, int>> dirs = { { -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, -1 },{ 0, 1 },{ 1, -1 },{ 1, 0 },{ 1, 1 } };
	//state 00, 01, 10, 11.   第一位表示下一代死活，第二位表示这一代死活义。
	int isAlive(vector<vector<int>>& board, int x, int y, int m, int n)
	{
		if (x < 0 || x >= m) return 0;
		if (y < 0 || y >= n) return 0;
		return board[x][y] & 1;
	}
	int change(vector<vector<int>>& board, int x, int y, int live)
	{
		board[x][y] += (board[x][y] ? live == 2 || live == 3 : live == 3) << 1;
	}
	int nearLive(vector<vector<int>>& board, int x, int y, int m, int n)
	{
		int live = 0;
		for (int i = 0; i < dirs.size(); i++)
			live += isAlive(board, x + dirs[i].first, y + dirs[i].second, m, n);
		return live;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (m == 0) return;
		int n = board[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int live = nearLive(board, i, j, m, n);
				change(board, i, j, live);
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = board[i][j] >> 1;
	}
};
