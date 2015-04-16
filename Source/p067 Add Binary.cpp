#include "leetcode.h"


/**
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
	string addBinary(string a, string b) {
		int len = max(a.length(), b.length()) + 1;
		vector<int> va(len, 0), vb(len, 0), vc(len, 0);
		for (int i = 0; i < a.length(); i++) va[a.length() - i - 1] = a[i] - '0';
		for (int i = 0; i < b.length(); i++) vb[b.length() - i - 1] = b[i] - '0';
		for (int i = 0; i < len - 1; i++)
		{
			vc[i] += va[i] + vb[i];
			vc[i + 1] += vc[i] >> 1;
			vc[i] &= 1;
		}
		while (vc.size() > 1 && vc.back() == 0) vc.erase(vc.end() - 1);
		string res = "";
		for (auto x = vc.rbegin(); x < vc.rend(); x++) res += *x + '0';
		return res;
	}
};