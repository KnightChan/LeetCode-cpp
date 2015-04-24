#include "leetcode.h"

/**
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

1
/ \
2   3
/
4
\
5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

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
	vector<TreeNode *> generateTrees(int n) {
		return dfs(1, n);
	}

	vector<TreeNode *> dfs(int l, int r)
	{
		if (l > r)
			return vector<TreeNode *>{nullptr};
		vector<TreeNode *> ans;
		for (int i = l; i <= r; i++)
		{
			vector<TreeNode *> left = dfs(l, i - 1);
			vector<TreeNode *> right = dfs(i + 1, r);
			for (auto lr : left)
				for (auto rr : right)
				{
				TreeNode *root = new TreeNode(i);
				root->left = lr;
				root->right = rr;
				ans.push_back(root);
				}
		}
		return ans;
	}
};

/*
int main()
{
	auto ans = Solution().generateTrees(0);
	cout << ans.size();
	return 0;
}
//*/