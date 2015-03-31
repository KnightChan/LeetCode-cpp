#include <iostream>
using namespace std;

class Solution {
	/*
	 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
	*/
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string ans = "";
		int t_blanks = 2 * nRows - 2;
		for (int i = 0; i < nRows; i++){
			for (int j = i, k = t_blanks - 2 * i; j < s.length(); j += k, k = t_blanks - k){
				if (k <= 0) continue;
				ans += s.substr(j, 1);
			}
		}
		return ans;
	}
};


/*
int main()
{
	cout << Solution().convert("A", 1).c_str() << endl;
	return 0;
}
//*/