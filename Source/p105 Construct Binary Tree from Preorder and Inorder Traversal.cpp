#include "leetcode.h"

/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* helper(vector<int>& preorder, int pb, int pe, vector<int>& inorder, int ib, int ie)
	{
		if (pe < pb) return NULL;
		TreeNode* node = new TreeNode(preorder[pb]);
		int ll = find(inorder.begin() + ib, inorder.begin() + ie + 1, preorder[pb]) - inorder.begin();
		node->left = helper(preorder, pb + 1, pb + ll - ib, inorder, ib, ll - 1);
		node->right = helper(preorder, pb - ib + ll + 1, pe, inorder, ll + 1, ie);
		return node;
	}
};