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
    int goodNodes(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }

        int max = root->val;
        int count = 0;

        recurse(root, max, count);

        return count;
        
    }

    void recurse(TreeNode* current, int max, int& count)
    {
        cout << current->val;
        if (current->val >= max)
        {
            
            count++;
        }

        int old_max = max;

        if (current->left)
        {
            if (current->left->val > max)
            {
                max = current->left->val;
            }
            recurse(current->left, max, count);
        }

        max = old_max;

        if (current->right)
        {
            if (current->right->val > max)
            {
                max = current->right->val;
            }
            recurse(current->right, max, count);
        }

        return;
    }
};
