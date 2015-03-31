#include <iostream>
using namespace std;

class Solution {
	/**
	Implement atoi to convert a string to an integer.

	Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

	Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

	Update (2015-02-10):
	The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
	*/
public:
	int atoi(string str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		long sign = 1, start = 0;
		if (str[0] == '+')
			start = 1;
		if (str[0] == '-')
		{
			start = 1;
			sign = -1;
		}
		long ans = 0;
		for (int i = start; i < str.length(); i++){
			if (str[i] > '9' || str[i] < '0' || i > 11)
				break;
			ans = ans * 10 + str[i] - '0';
		}
		ans *= sign;
		if (ans < INT_MIN)
			ans = INT_MIN;
		if (ans > INT_MAX)
			ans = INT_MAX;
		return ans;
	}
};

/*
int main()
{
	cout << Solution().atoi("-1") << endl;
	return 0;
}
//*/