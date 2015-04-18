#include "leetcode.h"


/**
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
"This    is    an",
"example  of text",
"justification.  "
]

Note: Each word is guaranteed not to exceed L in length.
*/

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		int ws = 0, wl = 0;
		vector<string> ans;
		for (int i = 0; i < words.size(); i++)
		{
			wl += words[i].length();
			if (wl + i - ws > L)
			{
				wl -= words[i].length();
				int space = L - wl;
				int onemore = i - ws - 1 > 0?space % (i - ws - 1):0;
				space = i - ws - 1 > 0 ? space/(i - ws - 1):0;
				string s = words[ws], sspace(space, ' ');
				for (int j = ws + 1; j < i; j++, onemore--)
				{
					if (onemore > 0)
						s += sspace + " " + words[j];
					else s += sspace + words[j];
				}
				s += string(L - s.length(), ' ');
				ans.push_back(s);
				
				wl = words[i].length();
				ws = i;
			}
		}
		if (words.size() > ws)
		{
			string s(words[ws]), sspace(L - wl - (words.size() - ws - 1), ' ');
			for (int j = ws + 1; j < words.size(); j++)
				s += " " + words[j];
			s += sspace;
			ans.push_back(s);
		}
		return ans;
	}
};

/*
int main()
{
	auto ans = Solution().fullJustify(vector < string > {"This", "is", "an", "example", "of", "text", "justification."}, 16);
	auto ans1 = Solution().fullJustify(vector < string > {""}, 0);
	displayVector(ans);
	cout << endl;
	displayVector(ans1);
	cout << endl;
	auto ans2 = Solution().fullJustify(vector < string > {"a", "b", "c", "d", "e"}, 1);
	displayVector(ans2);
	cout << endl;
	return 0;
}
//*/