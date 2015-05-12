#include "leetcode.h"

/**
Given inorder and postorder traversal of a tree, construct the binary tree.

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return helper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* helper(vector<int>& postorder, int pb, int pe, vector<int>& inorder, int ib, int ie)
	{
		if (pe < pb) return NULL;
		TreeNode* node = new TreeNode(postorder[pe]);
		int ll = find(inorder.begin() + ib, inorder.begin() + ie + 1, postorder[pe]) - inorder.begin();
		node->left = helper(postorder, pb, pb + ll - ib - 1, inorder, ib, ll - 1);
		node->right = helper(postorder, pb - ib + ll, pe - 1, inorder, ll + 1, ie);
		return node;
	}
};