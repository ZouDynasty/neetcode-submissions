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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<vector<int>> layer_traversal;

        if (!root)
        {
            return {};
        }

        recurse(root, layer_traversal, 0);

        vector<int> right_visible;

        for (int i = 0; i < layer_traversal.size(); i++)
        {
            right_visible.push_back(layer_traversal[i][layer_traversal[i].size() - 1]);
        }

        return right_visible;


    }
    void recurse(TreeNode* current, vector<vector<int>>& layer_traversal, int layer)
    {
        if (layer_traversal.size() == layer)
        {
            layer_traversal.push_back({});
        }

        layer_traversal[layer].push_back(current->val);

        layer++;

        if (!current->left && !current->right)
        {
            return;
        }
        if (current->left)
        {
            recurse(current->left, layer_traversal, layer);
        }
        if (current->right)
        {
            recurse(current->right, layer_traversal, layer);
        }

        return;
    }
};
