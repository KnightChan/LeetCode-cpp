#include "leetcode.h"

/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

*/

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ans;
		vector<int> now;
		dfs(n, 1, k, now, ans);
		return ans;
	}

	void dfs(int n, int start, int count, vector<int> &now, vector<vector<int> > &ans)
	{
		if (count == 0)
		{
			ans.push_back(vector<int>(now));
			return;
		}
		for (int i = start; i <= n; i++)
		{
			now.push_back(i);
			dfs(n, i + 1, count - 1, now, ans);
			now.pop_back();
		}
	}
};

class Solution1 {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ans;
		vector<int> now;
		return dfs(n, 1, k, now);
	}

	vector<vector<int> > dfs(int n, int start, int count, vector<int> &now)
	{
		if (count == 0)
		{
			vector<vector<int> > ans{ vector<int>(now) };
			return ans;
		}
		vector<vector<int> > ans;
		for (int i = start; i <= n; i++)
		{
			now.push_back(i);
			auto x = dfs(n, i + 1, count - 1, now);
			//ans.insert(ans.end(), x.begin(), x.end());
			auto x1 = ans;
			ans.resize(x1.size() + x.size());
			merge(x1.begin(), x1.end(), x.begin(), x.end(), ans.begin());
			now.pop_back();
		}
		return ans;
	}
};