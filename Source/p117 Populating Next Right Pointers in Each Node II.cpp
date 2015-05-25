#include "leetcode.h"

/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL


*/

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode *cur_level = root, *next_level;
		while (cur_level)
		{
			auto tmp = find_next(cur_level);
			next_level = tmp.first;
			cur_level = tmp.second;
			while (cur_level)
			{
				TreeLinkNode *x = NULL;
				if (cur_level->left && cur_level->right)
				{
					cur_level->left->next = cur_level->right;
					x = cur_level->right;
				}
				else {
					x = cur_level->left ? cur_level->left : cur_level->right;
				}
				auto n1 = find_next(cur_level->next);
				x->next = n1.first;
				cur_level = n1.second;
			}
			cur_level = next_level;
		}
	}

	pair<TreeLinkNode*, TreeLinkNode*>find_next(TreeLinkNode *cur)
	{
		if (!cur) return make_pair<TreeLinkNode*, TreeLinkNode*>(NULL, NULL);
		while (cur)
		{
			if (cur->left) return make_pair(cur->left, cur);
			if (cur->right) return make_pair(cur->right, cur);
			cur = cur->next;
		}
		return make_pair<TreeLinkNode*, TreeLinkNode*>(NULL, NULL);
	}
};

/*
int main()
{
	TreeLinkNode *a = new TreeLinkNode(1);
	a->right = new TreeLinkNode(-9);
	a->right->right = new TreeLinkNode(8);
	a->right->right->left = new TreeLinkNode(4);
	a->right->right->right = new TreeLinkNode(-3);
	Solution().connect(a);
	return 0;
}
//*/