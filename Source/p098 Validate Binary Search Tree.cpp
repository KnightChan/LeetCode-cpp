#include "leetcode.h"

/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}

	bool isValidBST(TreeNode *root, long long l, long long r)
	{
		if (root == NULL) return true;
		if (root->val < l || root->val > r) return false;
		return isValidBST(root->left, l, (long long)(root->val) - 1) && isValidBST(root->right, (long long)(root->val) + 1, r);
	}
};

/*
int main()
{
	TreeNode *root = new TreeNode(-2147483648);
	root->left = new TreeNode(-2147483648);
	cout << Solution().isValidBST(root) << endl;
	return 0;
}
//*/