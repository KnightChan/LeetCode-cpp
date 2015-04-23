#include "leetcode.h"

/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

1
\
2
/
3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
	vector<int> inorderTraversal(TreeNode *root) {
		if (root == NULL) return vector<int>(0);
		vector<int> left = inorderTraversal(root->left);
		vector<int> right = inorderTraversal(root->right);
		vector<int> ans(left);
		ans.push_back(root->val);
		ans.insert(ans.end(), right.begin(), right.end());
		return ans;
	}
};