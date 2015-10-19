#include "leetcode.h"

/**
Given a string of numbers and operators, 
return all possible results from computing all the different possible 
ways to group numbers and operators. The valid operators are +, - and *.


*/



class Solution {
public:
	unordered_set<char> ops = { '+', '-', '*' };

	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		bool flag = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (ops.count(input[i]))
			{
				flag = false;
				auto res1 = diffWaysToCompute(input.substr(0, i));
				auto res2 = diffWaysToCompute(input.substr(i + 1, input.length() - i - 1));
				for (int j = 0; j < res1.size(); j++)
					for (int k = 0; k < res2.size(); k++)
					{
						if (input[i] == '+')
							res.push_back(res1[j] + res2[k]);
						else if (input[i] == '-')
							res.push_back(res1[j] - res2[k]);
						else if (input[i] == '*')
							res.push_back(res1[j] * res2[k]);
					}
			}
		}
		if (flag)
		{
			int tmp = 0;
			for (int i = 0; i < input.length(); i++)
				tmp = tmp * 10 + input[i] - '0';
			res.push_back(tmp);
		}
		return res;
	}
};

