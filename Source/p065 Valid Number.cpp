#include "leetcode.h"

#include <regex>

/**
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

*/

/*
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution {
	public boolean isNumber(String s) {
		Pattern pattern = Pattern.compile(" *[+-]?((\\d+\\.?\\d*)|(\\d*\\.?\\d+))((e|E)[+-]?\\d+)? *");
		Matcher matcher = pattern.matcher(s);
		return matcher.matches();
	}
}
*/

//leetcode does not support regex, so here I use JAVA to AC it.
class Solution {
public:
	bool isNumber(string s) {
		regex reg(" *[+-]?((\\d+\\.?\\d*)|(\\d*\\.?\\d+))((e|E)[+-]?\\d+)? *");
		return regex_match(s, reg);
	}
};



/*
int main()
{

	return 0;
}
//*/