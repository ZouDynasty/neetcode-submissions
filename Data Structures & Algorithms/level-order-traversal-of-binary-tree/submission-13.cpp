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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root)
        {
            return {};
        }
        if (!root->left && !root->right)
        {
            return {{root->val}};
        }

        unordered_map<int, vector<int>> node_layers;

        int max_layers = 0;

        vector<vector<int>> traversal(0);

        recurse(root, traversal, 0);

        return traversal;
    }

    void recurse(TreeNode* current, vector<vector<int>>& traversal, int layer)
    {
        if (traversal.size() == layer)
        {
            traversal.push_back({});
        }
        
        traversal[layer].push_back(current->val);

        layer++;

        if (!current->left && !current->right)
        {
            return;
        }

        if (current->left)
        {
            recurse(current->left, traversal, layer);
        }
        if (current->right)
        {
            recurse(current->right, traversal, layer);
        }

        return;
    }
};
