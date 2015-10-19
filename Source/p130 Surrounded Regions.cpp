#include "leetcode.h"

/**
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X


*/
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;
        
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) if (board[i][0] == 'O') q.push(make_pair(i, 0));
        for (int i = 0; i < m; i++) if (board[i][n-1] == 'O') q.push(make_pair(i, n - 1));
        for (int i = 0; i < n; i++) if (board[0][i] == 'O') q.push(make_pair(0, i));
        for (int i = 0; i < n; i++) if (board[m-1][i] == 'O') q.push(make_pair(m - 1, i));
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if (board[x][y] != 'O') continue;
            board[x][y] = 'Q';
            for (int i = 0; i < 4; i++)
            if (check(x + dirs[i][0], y + dirs[i][1], m, n) 
            && board[x + dirs[i][0]][y + dirs[i][1]] == 'O')
                q.push(make_pair(x + dirs[i][0], y + dirs[i][1]));
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i][j] == 'Q'?'O':'X';
    }
    
    bool check(const int &x, const int &y, const int &m, const int &n)
    {
        if (x >= m) return false;
        if (x < 0) return false;
        if (y >= n) return false;
        if (y < 0) return false;
        return true;
    }
};

