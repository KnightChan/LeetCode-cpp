#include "leetcode.h"

/**
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


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
	void flatten(TreeNode* root) {
		helper(root);
	}

	TreeNode* helper(TreeNode* root) {
		if (!root) return NULL;
		if (!root->left && !root->right) return root;
		TreeNode* leftTail = NULL, *rightTail = NULL;
		leftTail = helper(root->left);
		rightTail = helper(root->right);
		if (leftTail)
		{
			leftTail->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		return rightTail ? rightTail : leftTail;
	}
};