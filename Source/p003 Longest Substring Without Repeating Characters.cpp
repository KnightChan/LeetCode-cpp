#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

/**
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
	/*22ms*/
	int lengthOfLongestSubstring(string s) {
		bool flag[256];
		memset(flag, false, sizeof(flag));
		int ansl = 0;
		int l = -1, len = 0, flen = 0;
		for (unsigned int i = 0; i < s.length(); i++){
			if (flag[s[i]]){
				do{
					l++;
					flag[s[l]] = false;
					flen -= 1;
				} while (s[i] != s[l]);
			}
			flag[s[i]] = true;
			flen += 1;
			if (flen > len)
				len = flen;
		}
		return len;
	}

	/*122ms*/
	int lengthOfLongestSubstring1(string s) {
		set<char> seta;
		int ansl = 0;
		int l = -1, len = 0;
		for (unsigned int i = 0; i < s.length(); i++){
			set<char>::iterator iter = seta.find(s[i]);
			if (iter != seta.end()){
				do{
					l++;
					seta.erase(s[l]);
				} while (s[i] != s[l]);
			}
			seta.insert(s[i]);
			if (seta.size() > len)
				len = seta.size();
		}
		return len;
	}

	/*80ms*/
	int lengthOfLongestSubstring2(string s) {
		unordered_set<char> seta;
		int ansl = 0;
		int l = -1, len = 0;
		for (unsigned int i = 0; i < s.length(); i++){
			unordered_set<char>::iterator iter = seta.find(s[i]);
			if (iter != seta.end()){
				do{
					l++;
					seta.erase(s[l]);
				} while (s[i] != s[l]);
			}
			seta.insert(s[i]);
			if (seta.size() > len)
				len = seta.size();
		}
		return len;
	}
};

/*
int main()
{
	string s = "umvejcuuk";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
	return 0;
}
//*/