#include "leetcode.h"

/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3

But the following is not:

1
/ \
2   2
\   \
3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
	bool isSymmetric(TreeNode *root) {
		if (!root) return true;
		return dfs(root->left, root->right);
	}

	bool dfs(TreeNode *p, TreeNode *q)
	{
		if (!p && !q) return true;
		if (!p || !q) return false;
		if (p->val != q->val) return false;
		return dfs(p->left, q->right) && dfs(p->right, q->left);
	}
};
