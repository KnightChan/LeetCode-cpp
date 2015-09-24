#include "leetcode.h"

/**
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		wordList.insert(endWord);

		queue<string> q;
		q.push(beginWord);
		q.push("#");
		if (wordList.count(beginWord))
			wordList.erase(beginWord);

		unordered_map<string, vector<string>> path_links;

		unordered_set<string> nextLvl;
		while (q.size() > 1)
		{
			string cur = q.front();
			q.pop();
			if (cur == "#")
			{
				if (nextLvl.count(endWord)) break;
				q.push("#");
				nextLvl.clear();
				continue;
			}
			for (int i = 0; i < cur.length(); i++)
			{
				string next = cur;
				for (char c = 'a'; c <= 'z'; c++)
					if (c != cur[i])
					{
						next[i] = c;
						if (nextLvl.count(next))
							path_links[next].push_back(cur);
						if (wordList.find(next) != wordList.end())
						{
							q.push(next);
							nextLvl.insert(next);
							path_links[next].push_back(cur);
							wordList.erase(next);
						}
					}
			}
		}
		vector<vector<string>> res;
		vector<string> curpath(1, endWord);
		dfs(beginWord, res, curpath, endWord, path_links);
		return res;
	}

	void dfs(const string &beginWord, vector<vector<string>> &ans, vector<string> &curpath, string cur, unordered_map<string, vector<string>> &path_links)
	{
		if (cur == beginWord)
		{
			ans.push_back(vector<string>(curpath.rbegin(), curpath.rend()));
			return;
		}
		for (string next : path_links[cur])
		{
			curpath.push_back(next);
			dfs(beginWord, ans, curpath, next, path_links);
			curpath.pop_back();
		}
	}
};

