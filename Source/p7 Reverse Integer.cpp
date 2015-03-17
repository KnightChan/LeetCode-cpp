#include <iostream>
using namespace std;

class Solution {
	/*
	Reverse digits of an integer.

	Example1: x = 123, return 321
	Example2: x = -123, return -321
	*/
public:
	int reverse(int x) {
		int sign = 1;
		if (x < 0){
			x = -x;
			sign = -1;
		}
		long long ans = 0;
		while (x > 0){
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		ans *= sign;
		if (ans > INT_MAX || ans < INT_MIN)
			return 0;
		return ans;
	}
};


/*
int main()
{
	cout << Solution().reverse(1534236469) << endl;
	return 0;
}
//*/