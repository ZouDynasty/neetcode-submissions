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
    bool isBalanced(TreeNode* root) 
    {
        bool valid = true;
        dfs(root, valid);
        return valid;
    }
    int dfs(TreeNode* curr, bool& valid)
    {
        if (curr == nullptr)
        {
            return 0;
        }

        int left = dfs(curr->left, valid);
        int right = dfs(curr->right, valid);

        if (abs(left - right) > 1)
        {
            valid = false;
            return 0;
        }

        return max(left, right) + 1;
    }
};
