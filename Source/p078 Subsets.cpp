#include "leetcode.h"

/**
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*/


class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>  > ans;
		vector<int> now;
		sort(S.begin(), S.end());
		dfs(S, 0, now, ans);
		return ans;
	}

	void dfs(vector<int> &S, int start, vector<int> &now, vector<vector<int> > &ans)
	{
		ans.push_back(vector<int>(now));
		for (int i = start; i < S.size(); i++)
		{
			now.push_back(S[i]);
			dfs(S, i + 1, now, ans);
			now.pop_back();
		}
	}
};