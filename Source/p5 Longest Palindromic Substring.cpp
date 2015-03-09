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
		string newStr = "#";
		for (char ch : s){
			newStr += (string)ch + "#";
		}
		cout << s.c_str() << endl;
		cout << newStr.c_str() << endl;
		int *lens = new int[newStr.length()];
		memset(lens, 0, sizeof(lens));

		int center = 0, right = 0, maxl, maxs;
		for (int i = 0; i < newStr.length(); i++){
			int j = 2 * center - i;
			if (i + lens[j] < right)
				lens[i] = lens[j];
			else{
				lens[i] = right - i + 1;
				while (i >= lens[i]
					&& newStr[i + lens[i]] == newStr[i - lens[i]])
					lens[i]++;
				if (i + lens[i] > right){
					right = i + lens[i];
					center = i;
				}
			}
			if (maxl > lens[i]){
				maxl = lens[i];
				maxs = i - maxl;
			}
		}
		cout << newStr.c_str() << endl;
		cout << maxs << maxl << endl;
		string ans = "";
		for (int i = maxs; i < maxs + 2 * maxl; i++)
			if (newStr[i] != '#')
				ans += newStr[i];
		return ans;
	}
};

//*
int main()
{
	string s = "ccc";
	cout << Solution().longestPalindrome(s).c_str() << endl;
	return 0;
}
//*/