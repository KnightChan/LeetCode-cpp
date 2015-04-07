#include "leetcode.h"


/**
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> a, b;
		for (int i = num1.length() - 1; i >= 0; i--)
			a.push_back(num1[i] - '0');
		for (int i = num2.length() - 1; i >= 0; i--)
			b.push_back(num2[i] - '0');
		vector<int> c(num1.length() + num2.length() + 1, 0);
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++)
				c[i + j] += a[i] * b[j];
		for (int i = 0; i < c.size() - 1; i++)
			if (c[i] > 9){
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			}
		int anslen = c.size() - 1;
		while (anslen > 0 && c[anslen] == 0) --anslen;
		string ans;
		for (int i = anslen; i >= 0; i--)
			ans.push_back(c[i] + '0');
		return ans;
	}
};


/*
int main()
{
	cout << Solution().multiply("9", "9") << endl;
	vector<int> v(3, -1);
	v[1] = 3;
	v.pop_back();
	displayVector(v);
	v.push_back(2);
	displayVector(v);
	return 0;
}
//*/