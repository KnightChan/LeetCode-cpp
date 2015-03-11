#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
	/**
	Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
	*/
public:
	//use Manacher Algorithm, O(n)
	string longestPalindrome(string s) {
		string newStr = "$#";
		for (char ch : s){
			char t[2] = { ch, '\0' };
			newStr += (string)t + "#";
		}
		int *lens = new int[newStr.length()];

		int center = 0, right = 0, maxl = 0, maxs = -1;
		for (int i = 0; i < newStr.length(); i++){
			int j = 2 * center - i;
			if (right > i)
				lens[i] = lens[j] + i < right ? lens[j] : right - i;
			else
				lens[i] = 1;
			while (newStr[i + lens[i]] == newStr[i - lens[i]])
				lens[i]++;
			if (lens[i] + i - 1 > right){
				right = lens[i] + i - 1;
				center = i;
			}
			if (maxl < lens[i] - 1){
				maxl = lens[i] - 1;
				maxs = i - maxl;
			}
		}
		string ans = "";
		for (int i = maxs; i < maxs + 2 * maxl; i++)
			if (newStr[i] != '#')
				ans += newStr[i];
		return ans;
	}
};

/*
int main()
{
	string s = "abb";
	cout << Solution().longestPalindrome(s).c_str() << endl;
	return 0;
}
//*/