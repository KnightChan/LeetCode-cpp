#include "leetcode.h"

/**
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}

	TreeNode* helper(vector<int>& nums, int s, int e) {
		if (s > e) return NULL;
		int mid = (s + e) >> 1;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = helper(nums, s, mid - 1);
		node->right = helper(nums, mid + 1, e);
		return node;
	}
};