#include <iostream>
using namespace std;

class Solution {
	/**
	Determine whether an integer is a palindrome. Do this without extra space.
	
	*/
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int y = 0;
		while (y < x){
			y = y * 10 + x % 10;
			if (y == 0)
				return false;
			x /= 10;
		}
		if (y == x || y / 10 == x)
			return true;
		return false;
	}
};

/*
int main()
{
	cout << Solution().isPalindrome(10) << endl;
	return 0;
}
//*/