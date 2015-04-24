#include "leetcode.h"

/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		auto ans = levelOrder(root);
		for (int i = 1; i < ans.size(); i += 2)
			reverse(ans[i].begin(), ans[i].end());
		return ans;
	}

	vector<vector<int> > levelOrder(TreeNode *root) {
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
		return ans;
	}
};


class Solution2 {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		auto ans = levelOrder(root);
		for (int i = 1; i < ans.size(); i += 2)
			reverse(ans[i].begin(), ans[i].end());
		return ans;
	}

	vector<vector<int> > levelOrder(TreeNode *root) {
		if (!root) return vector<vector<int> >();
		vector<vector<int> > ans;
		dfs(root, 0, ans);
		return ans;
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