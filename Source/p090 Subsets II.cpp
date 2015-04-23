#include "leetcode.h"

/**
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

*/

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > ans;
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
			if (i > 0 && S[i] == S[i - 1])
			{
				if (i == start && !now.empty() && now.back() == S[i])
					; else continue;
			}
			now.push_back(S[i]);
			dfs(S, i + 1, now, ans);
			now.pop_back();
		}
	}
};