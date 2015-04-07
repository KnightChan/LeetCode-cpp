#include "leetcode.h"

/**
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/

class Solution {
public:
	int totalNQueens(int n) {
		return dfs(0, 0, 0, 0, n);
	}

	int dfs(unsigned col, unsigned ls, unsigned rs, int i, int n)
	{
		if (i == n) return 1;
		unsigned choose = ((1 << n) - 1) & ~(col | ls | rs);
		int ans = 0;
		while (choose)
		{
			unsigned t = choose & ~(choose - 1);
			choose ^= t;
			ans += dfs(col | t, (ls | t) >> 1, (rs | t) << 1, i + 1, n);
		}
		return ans;
	}
};

/*
int main()
{
	auto ans = Solution().totalNQueens(14);
	cout << ans << endl;
	return 0;
}
//*/