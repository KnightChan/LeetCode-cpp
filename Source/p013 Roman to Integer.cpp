#include <iostream>
#include <map>
using namespace std;

class Solution {
	/**
	Given a roman numeral, convert it to an integer.

	Input is guaranteed to be within the range from 1 to 3999.
	*/
public:
	int romanToInt(string s) {
		string keys[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		int index = 0, num = 0, t = 0;
		while (index < 13 && t < s.length()){
			while (s.substr(t, keys[index].length()) == keys[index]){
				t += keys[index].length();
				num += values[index];
			}
			++index;
		}
		return num;
	}
};

/*
int main()
{
}
//*/