#include "leetcode.h"

/**
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
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
	TreeNode* sortedListToBST(ListNode* head) {
		return helper(head, NULL);
	}

	TreeNode* helper(ListNode* head, ListNode* tail) {
		if (head == tail) return NULL;
		ListNode* mid = head, *tmp = head;
		while (tmp != tail && tmp->next != tail)
		{
			mid = mid->next;
			tmp = tmp->next->next;
		}
		TreeNode* node = new TreeNode(mid->val);
		node->left = helper(head, mid);
		node->right = helper(mid->next, tail);
		return node;
	}
};