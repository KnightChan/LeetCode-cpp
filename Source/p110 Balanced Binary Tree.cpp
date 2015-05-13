#include "leetcode.h"


/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
	bool isBalanced(TreeNode* root) {
		int h;
		return helper(root, h);
	}

	bool helper(TreeNode* root, int &h)
	{
		if (!root)
		{
			h = 0;
			return true;
		}
		int h1, h2;
		bool ans = helper(root->left, h1);
		ans &= helper(root->right, h2);
		h = max(h1, h2) + 1;
		return ans & (abs(h1 - h2) < 2);
	}
};