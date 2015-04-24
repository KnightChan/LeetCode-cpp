#include "leetcode.h"

/**
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
	void recoverTree(TreeNode *root) {
		auto nodes = findBadNodeInBST(root);
		TreeNode *first, *second;
		for (int i = 0; i < nodes.size() - 1; i++)
		{
			if (nodes[i]->val > nodes[i + 1]->val)
			{
				first = nodes[i];
				break;
			}
		}
		for (int i = nodes.size() - 1; i > 0; i--)
		{
			if (nodes[i] < nodes[i - 1])
			{
				second = nodes[i];
				break;
			}
		}
		swap(first->val, second->val);
	}

	vector<TreeNode *> findBadNodeInBST(TreeNode *root)
	{
		static bool first = true;
		if (root == NULL) return vector<TreeNode *>(0);
		if (root->left == NULL && root->right == NULL) return vector<TreeNode *>(1, root);
		auto left = findBadNodeInBST(root->left);
		auto right = findBadNodeInBST(root->right);
		vector<TreeNode *> ans(left);
		ans.push_back(root);
		ans.insert(ans.end(), right.begin(), right.end());
		return ans;
	}
};


class Solution2 {
public:
	void recoverTree(TreeNode *root) {
		vector<TreeNode *> nodes;
		findBadNodeInBST(root, nodes);
		vector<int> a;
		for (auto x : nodes)
			a.push_back(x->val);
		sort(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++)
			nodes[i]->val = a[i];
	}

	void findBadNodeInBST(TreeNode *root, vector<TreeNode *> &nodes)
	{
		if (root == NULL) return;
		findBadNodeInBST(root->left, nodes);
		nodes.push_back(root);
		findBadNodeInBST(root->right, nodes);
	}
};

class Solution3 {
public:
	void recoverTree(TreeNode *root) {
		TreeNode *first = NULL, *second = NULL, *pred = NULL;
		dfs(root, first, second, pred);
		swap(first->val, second->val);
	}

	void dfs(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&pred)
	{
		if (!root) return;
		dfs(root->left, first, second, pred);
		if (pred && pred->val > root->val)
		{
			if (!first) first = pred;
			second = root;
		}
		pred = root;
		dfs(root->right, first, second, pred);
	}
};

/*
int main()
{
	TreeNode *r = new TreeNode(2);
	r->left = new TreeNode(3);
	r->right = new TreeNode(1);
	r = new TreeNode(0);
	r->left = new TreeNode(1);
	Solution().recoverTree(r);
	cout << r->val << r->left->val << endl;
	return 0;
}
//*/