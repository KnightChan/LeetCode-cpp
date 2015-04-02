#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/**
	Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 

	*/
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		dfs(digits, "", ans);
		return ans;
	}

	string get_string(char c)
	{
		static string dic[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		return dic[c - '0'];
	}

	void dfs(string digits, string now, vector<string>& ans)
	{
		if (digits.size() == 0)
		{
			if (now != "")
				ans.push_back(now);
			return;
		}
		string s = get_string(digits[0]);
		for (int i = 0; i < s.length(); i++)
			dfs(digits.substr(1, digits.length() - 1), now + s.substr(i, 1), ans);
	}
};

/*
int main()
{
	string s = "23";
	vector<string> ans = Solution().letterCombinations(s);
	for (auto s : ans)
		cout << s.c_str() << " ";
	cout << endl;
}
//*/