#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/**
	Write a function to find the longest common prefix string amongst an array of strings. 
	*/
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty())
			return string("");
		for (int ans = 0; ans < strs[0].length(); ans++){
			char c = strs[0][ans];
			for (int i = 1; i < strs.size(); i++){
				if (ans >= strs[i].length() || c != strs[i][ans])
					return strs[0].substr(0, ans);
			}
		}
		return strs[0];
	}
};

/*
int main()
{
}
//*/