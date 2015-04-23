#include "leetcode.h"

/**
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		dfs(s, 0, 4, "", ans);
		return ans;
	}

	void dfs(string s, int start, int dot, string now, vector<string> &ans)
	{
		if (s.size() <= start && dot == 0)
		{
			ans.push_back(now.substr(1));
			return;
		}
		if (s.size() <= start || dot == 0) return;
		int one, two, three;
		if (s.size() >= 1) one = atoi(s.substr(start, 1).c_str());
		if (s.size() >= 2) two = atoi(s.substr(start, 2).c_str());
		if (s.size() >= 3) three = atoi(s.substr(start, 3).c_str());
		dfs(s, start + 1, dot - 1, now + "." + s.substr(start, 1), ans);
		if (two > 9) dfs(s, start + 2, dot - 1, now + "." + s.substr(start, 2), ans);
		if (three > 99 && three < 256) dfs(s, start + 3, dot - 1, now + "." + s.substr(start, 3), ans);
	}
};

/*
int main()
{
	auto ans = Solution().restoreIpAddresses("0000");
	displayVector(ans);
	cout << endl;
	return 0;
}
//*/