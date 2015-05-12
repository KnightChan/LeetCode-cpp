#include "leetcode.h"

/**

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7

return its bottom-up level order traversal as:

[
[15,7],
[9,20],
[3]
]

*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		if (!root) return vector<vector<int> >();
		queue<TreeNode *> q({ root, NULL });
		vector<vector<int> > ans;
		vector<int> now;
		while (!q.empty())
		{
			auto x = q.front();
			q.pop();
			if (x == NULL)
			{
				if (!q.empty()) q.push(NULL);
				ans.push_back(vector<int>(now));
				now.clear();
				continue;
			}
			now.push_back(x->val);
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
		return vector<vector<int> >(ans.rbegin(), ans.rend());
	}
};


class Solution2 {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		if (!root) return vector<vector<int> >();
		vector<vector<int> > ans;
		dfs(root, 0, ans);
		return vector<vector<int> >(ans.rbegin(), ans.rend());;
	}

	void dfs(TreeNode *root, int depth, vector<vector<int> > &ans)
	{
		if (root == NULL) return;
		if (depth >= ans.size()) ans.push_back(vector<int>());
		ans[depth].push_back(root->val);
		dfs(root->left, depth + 1, ans);
		dfs(root->right, depth + 1, ans);
	}
};