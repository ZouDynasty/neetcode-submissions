/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root)
        {
            return true;
        }

        return recurse(root, INT_MAX, INT_MIN);

    }

    bool recurse(TreeNode* cur, int upper_bound, int lower_bound)
    {
        if (!cur)
        {
            return true;
        }
        
        if (cur->val <= lower_bound || cur->val >= upper_bound)
        {
            return false;
        }

        return recurse(cur->left, cur->val, lower_bound) && recurse(cur->right, upper_bound, cur->val);

    }
};
