#include "leetcode.h"

/**
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN/2;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode *r, int &wholeMax)
    {
        if (!r) return 0;
        int lsingle = dfs(r->left, wholeMax);
        int rsingle = dfs(r->right, wholeMax);
        int singleMax = max(r->val, max(lsingle, rsingle) + r->val);
        wholeMax = max(wholeMax, lsingle + rsingle + r->val);
        wholeMax = max(wholeMax, singleMax);
        return singleMax;
    }
};
