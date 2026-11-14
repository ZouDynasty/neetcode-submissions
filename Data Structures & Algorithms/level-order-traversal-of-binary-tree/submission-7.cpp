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

        recurse(root, node_layers, 0, max_layers);

        vector<vector<int>> traversal(max_layers);

        for (const auto& [key, row_nodes] : node_layers)
        {
            for (int i = 0; i < row_nodes.size(); i++)
            {
                traversal[key].push_back(row_nodes[i]);
            }
        }

        return traversal;
    }

    void recurse(TreeNode* current, unordered_map<int, vector<int>>& node_layers, int layer, int& max_layers)
    {
        // node has no children, return

        // node has one of two children
        // don't recurse on anything null

        // node has both children

        node_layers[layer].push_back(current->val);

        layer++;

        max_layers = max(layer, max_layers);

        if (!current->left && !current->right)
        {
            return;
        }

        if (current->left)
        {
            recurse(current->left, node_layers, layer, max_layers);
        }
        if (current->right)
        {
            recurse(current->right, node_layers, layer, max_layers);
        }

        return;
    }
};
