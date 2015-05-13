#include "leetcode.h"

/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1

return

[
[5,4,11,2],
[5,8,4,5]
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		dfs(root, sum, vector<int>(), ans);
		return ans;
	}

	void dfs(TreeNode* root, int sum, vector<int> cur, vector<vector<int>> &ans) {
		if (root == NULL) return;
		if (!root->left && !root->right && sum == root->val)
		{
			cur.push_back(root->val);
			ans.push_back(vector<int>(cur));
			cur.pop_back();
			return;
		}
		cur.push_back(root->val);
		dfs(root->left, sum - root->val, cur, ans);
		cur.pop_back();

		cur.push_back(root->val);
		dfs(root->right, sum - root->val, cur, ans);
		cur.pop_back();
	}
};