#include "leetcode.h"

/**
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        
        queue<string> q;
        q.push(beginWord);
        q.push("#");
        
        unordered_set<string> used;
        
        int ans = 2;
        while (q.size() > 1)
        {
            string cur = q.front();
            q.pop();
            if (cur == "#")
            {
                ans++;
                q.push("#");
                continue;
            }
            for (int i = 0; i < cur.length(); i++)
            for (char c = 'a'; c <= 'z'; c++)
            if (c != cur[i])
            {
                string next = cur;
                next[i] = c;
                
                if (wordList.find(next) == wordList.end() || used.find(next) != used.end())
                    continue;
                if (next == endWord) return ans;
                q.push(next);
                //wordList.erase(next);
                used.insert(next);
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        unordered_map<string, vector<string>> nodes_links;
        
        make_links(wordList, nodes_links);
        
        queue<string> q;
        unordered_map<string, int> used;
        q.push(beginWord);
        q.push("#");
        used[beginWord] = 0;
        
        int ans = 2;
        while (q.size() > 1)
        {
            string cur = q.front();
            q.pop();
            if (cur == "#")
            {
                ans++;
                q.push("#");
                continue;
            }
            for (string next : nodes_links[cur])
            {
                if (used.find(next) != used.end())
                    continue;
                if (next == endWord) return ans;
                q.push(next);
                used[next] = used[cur] + 1;
            }
        }
        return 0;
    }
    
    void make_links(unordered_set<string>& wordList, unordered_map<string, vector<string>> &nodes_links)
    {
        for (string word : wordList)
            nodes_links[word] = vector<string>();
        for (string word : wordList)
        {
            for (int i = 0; i < word.length(); i++)
            for (char c = 'a'; c <= 'z'; c++)
            {
                string next = word;
                next[i] = c;
                if (next != word && wordList.find(next) != wordList.end())
                {
                    nodes_links[word].push_back(next);
                }
            }
        }
    }
};
