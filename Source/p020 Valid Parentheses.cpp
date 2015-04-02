#include "leetcode.h"

/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s){
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else
			{
				if (st.empty() || st.top() + 2 < c)
					return false;
				st.pop();
			}
		}
		if (st.empty())
			return true;
		return false;
	}
};

/*
int main()
{
	string s = "()[]{}";
	cout << endl;
	cout << Solution().isValid(s) << endl;
}
//*/