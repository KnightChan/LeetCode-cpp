#include "leetcode.h"

/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			auto cur = st.top(); st.pop();
			res.push_back(cur->val);
			if (cur->left) st.push(cur->left);
			if (cur->right) st.push(cur->right);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
