#include "leetcode.h"

/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/

class Solution {
public:
	string simplifyPath(string path) {
		deque<string> dq;
		int last = 0;
		string ans;
		if (path[0] == '/') ans.push_back('/');
		path.push_back('/');
		for (int i = 0; i < path.length(); i++)
			if (path[i] == '/')
			{
			string s = path.substr(last, i - last);
			if (i - last == 0 || (s == "."))
			{
				//do nothing
			}
			else if (s == "..")
			{
				if (!dq.empty()) dq.pop_back();
			}
			else
			{
				dq.push_back(s);
			}
			last = i + 1;
			}
		while (!dq.empty())
		{
			if (dq.size() > 1) ans += dq.front() + "/";
			else ans += dq.front();
			dq.pop_front();
		}
		return ans;
	}
};