#include <iostream>
#include <map>
using namespace std;

class Solution {
	/**
	Given an integer, convert it to a roman numeral.

	Input is guaranteed to be within the range from 1 to 3999.
	*/
public:
	string intToRoman(int num) {
		string keys[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string s = "";
		int index = 0;
		while (num > 0){
			while (num >= values[index]){
				s += keys[index];
				num -= values[index];
			}
			++index;
		}
		return s;
	}
};

/*
int main()
{
}
//*/